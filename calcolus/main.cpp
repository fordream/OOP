#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <map>

#include "SocketException.h"
#include "ClientSocket.h"

#include "cfinder.h"
#include "clog.h"

using namespace std;

const string EMAIL	= "test%40gmail.com";
const string PASS 	= "test";
const string GID	= "11360525";		// ID нужной группы
const string HOST	= "192.168.137.1";	// IP-адрес компьютера, на котором есть HTTP-прокси
const int PORT		= 3126;				// Порт прокси-сервера

CLog log;

vector < string > scanTopicList (string, string);
vector < string > scanTopic (string, string);
vector < string > scanWall (string, string);
string makePostHeader (string, string, string, string);
string makeWikiTable (map < string , unsigned int >, string);
string makeGetHeader (string, string, string);
string makeRequest (string);
string getVkCookie (string, string);
void vectorToMap (map < string , unsigned int > &, vector < string >);
map < string , unsigned int > mapPlus (map < string , unsigned int >, map < string , unsigned int >);
int toInt (string);

template < typename T >
string toString (T);

int main ()
{
	log.push("START PROGRAM!");
	
	string cookie = getVkCookie(EMAIL, PASS);
	
	cout << "cookie: " << cookie << endl;
	
	if (cookie.empty())
		return 1;

	vector < string > tid_array = scanTopicList(GID, cookie);
	map < string , unsigned int > uid_topic_map, uid_wall_map, uid_all_map;

	for (vector < string >::iterator it_i = tid_array.begin(); it_i != tid_array.end(); ++it_i)
	{
		log.push("group", *it_i);		
		vectorToMap(uid_topic_map, scanTopic(*it_i, cookie));
	}

	vectorToMap(uid_wall_map, scanWall(GID, cookie));
	
	uid_all_map = mapPlus(uid_wall_map, uid_topic_map);
	
	cout << makeWikiTable(uid_wall_map, "Количество записей на стене") << endl;
	cout << makeWikiTable(uid_topic_map, "Количество записей в темах") << endl;
	cout << makeWikiTable(uid_all_map, "Общее количество записей") << endl;
	
	log.push("END PROGRAM!");

	return 0;
}

map < string , unsigned int > mapPlus (map < string , unsigned int > a, map < string , unsigned int > b)
{
	for (map < string , unsigned int >::iterator it = b.begin(); it != b.end(); ++it)
		a[it->first] += it->second;
		
	return a;
}

bool compare (pair < string , unsigned int > a, pair < string , unsigned int > b)
{
	return a.second > b.second;
}

string makeWikiTable (map < string , unsigned int > uid_map, string title)
{
	vector < pair < string , unsigned int > > b;

	for (map < string , unsigned int >::iterator it = uid_map.begin(); it != uid_map.end(); ++it)
		b.push_back(make_pair(it->first, it->second));
	
	sort(b.begin(), b.end(), compare);
	
	ostringstream oss;
	
	oss << "{|" << endl;
	oss << "|+ " << title << endl;
	oss << "|- " << endl;
	oss << "! # !! Человек !! Сообщения" << endl;
	
	unsigned int index = 0;
	
	for (vector < pair <string , unsigned int > >::iterator it = b.begin(); it != b.end(); ++it)
	{
		oss << "|-" << endl;
		oss << "| " << ++index << " || [[id" << it->first << "]] || '''" << it->second << "'''" << endl;
	}
	
	oss << "|}" << endl;
	
	return oss.str();
}

string makePostHeader (string host, string page, string cookie, string post_data)
{
	ostringstream oss;
	
	oss << "POST http://" << host << "/" << page << " HTTP/1.1\r\n";
	oss << "Host: " << host << "\r\n";
	
	if (!cookie.empty())
		oss << "Cookie: " << cookie << "\r\n";
		
	oss << "Content-Type: application/x-www-form-urlencoded\r\n";
	oss << "Content-Length: " << post_data.length() << "\r\n\r\n";
	oss << post_data;

	return oss.str();
}

string makeGetHeader (string host, string page, string cookie)
{
	ostringstream oss;
	
	oss << "GET http://" << host << "/" << page << " HTTP/1.1\r\n";
	oss << "Host: " << host << "\r\n";
	
	if (!cookie.empty())
		oss << "Cookie: " << cookie << "\r\n";
		
	oss << "\r\n";
	
	return oss.str();
}

string makeRequest (string header)
{	
	ClientSocket client_socket(HOST, PORT);
	string html, temp;	
	
	client_socket << header;

	try
	{
		while (1)
		{
			client_socket >> temp;			
			html += temp;
		}
	}
	catch (SocketException&) {}
	
	return html;
}

string getVkCookie (string email, string password)
{
	CFinder finder(makeRequest(makePostHeader("login.vk.com", "?act=login", "", "email=" + email + "&pass=" + password)));
	finder.setSource(makeRequest(makePostHeader("m.vk.com", "login", "", "op=slogin&s=" + finder.nextToken("<input type='hidden' name='s' value='", "'"))));
	
	return ("remixsid=" + finder.nextToken("remixsid=", ";"));
}

template < typename T >
string toString (T t)
{
	ostringstream oss;
	
	oss << t;
	
	return oss.str();
}

int toInt (string s)
{
	istringstream iss(s);
	int result;
	
	iss >> result;
	
	return result;
}

vector < string > scanTopic (string tid, string cookie)
{
	vector < string > result;

	for (int i = 0;; i += 5)
	{
		CFinder finder(makeRequest(makeGetHeader("m.vk.com", "topic" + tid + "&st=" + toString(i), cookie)));
		bool f = false;
		
		while (true)
		{
			string uid = finder.nextToken("href=\"/id", "\"");

			if (uid.empty())
				break;

			f = true;

			result.push_back(uid);
			log.push("topic", tid, uid);
		}

		if (!f)
			break;
	}

	return result;
}

vector < string > scanWall (string gid, string cookie)
{
	CFinder finder(makeRequest(makeGetHeader("m.vk.com", "group" + gid, cookie)));
	string navigator;
	
	while (true)
	{
		string temp = finder.nextToken("/group" + gid + "?&amp;st", ">");
		
		if (!temp.empty())
			navigator = temp;
		else
			break;
	}
	
	finder.setSource(navigator);

	int pages = toInt(finder.nextToken("=", "\""));
	vector < string > result;

	for (int i = 0; i <= pages; i += 5)
	{
		CFinder finder(makeRequest(makeGetHeader("m.vk.com", "group" + gid + "?st=" + toString(i), cookie)));
		bool f = false;
		
		while (true)
		{
			string uid = finder.nextToken("href=\"/id", "\"");

			if (uid.empty())
				break;

			f = true;

			result.push_back(uid);
			log.push("wall", uid);
		}

		if (!f)
			break;
	}

	return result;
}

vector < string > scanTopicList (string gid, string cookie)
{
	vector < string > result;

	for (int i = 0;; i += 5)
	{
		CFinder finder(makeRequest(makeGetHeader("m.vk.com", "topics" + gid + "?st=" + toString(i), cookie)));
		
		bool f = false;
		
		while (true)
		{
			string tid = finder.nextToken(" <a href=\"/topic", "&");
			
			if (tid.empty())
				break;
			
			f = true;
			result.push_back(tid);
		}
		
		if (!f)
			break;
	}
	
	return result;
}

void vectorToMap (map < string , unsigned int > &uid_map, vector < string > uid_array)
{
	for (vector < string >::iterator it_j = uid_array.begin(); it_j != uid_array.end(); ++it_j)
		++uid_map[*it_j];
}
