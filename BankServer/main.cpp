#include "Server.h"
//#include "../Public/MD5.h"

//#include "DAL/MysqlDB.h"
//#include "../Public/Exception.h"
//#include "../Public/Logging.h"
//#include "../Public/JUtil.h"
//#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace PUBLIC;
//using namespace DAL;
//using namespace std;
int main(void)
{
	//MD5 md5;

	//unsigned char hash[16];
	//md5.MD5Make(hash, (unsigned char const *)"cppcourse", 9);
	//int i;
	//for (i=0; i<16; ++i)
	//{
	//	printf("%0X", hash[i]);
	//}

	//printf("\n");

	//MysqlDB db;
	//try
	//{
	//	db.Open("localhost", "root", "root", "abcbank", 0);
	//	stringstream ss;
	//	ss << "select count(*) as total from " <<
	//		"(select * from trans where date_format(trans_date, '%Y-%m-%d')='2019-08-18') as a, abstract b where a.abstract_id = b.abstract_id;";
	//	MysqlRecordset rs = db.QuerySQL(ss.str().c_str());

	//	int total = Convert::StringToInt(rs.GetItem(0, "total"));


	//	ss.clear();
	//	ss.str("");
	//	ss << "select a.account_id, a.other_account_id, b.name, a.money, a.balance, a.trans_date from " <<
	//		"(select * from trans where date_format(trans_date, '%Y-%m-%d')='2019-08-18') a, abstract b where a.abstract_id = b.abstract_id order by a.trans_date limit " <<
	//		0 * 15 <<
	//		", 15;";

	//	rs.Clear();
	//	rs = db.QuerySQL(ss.str().c_str());
	//	if (rs.GetRows() < 1)	// no data found
	//		return 6;
	//	//cout << ss.str<< endl;
	//	for (unsigned int i = 0; i < rs.GetRows(); ++i)
	//	{
	//		//注意account_id为大写，否则出现vector越界
	//		cout << rs.GetItem(i, "account_id") << " " << rs.GetItem(i, "name") << endl; 
	//	}
	//}
	//catch (Exception& e)
	//{
	//	LOG_INFO << e.what();
	//	db.Close();
	//}

	//db.Close();
	return Singleton<Server>::Instance().Start();
}