#pragma once
#include "pch.h"
#include "ODBC.h"
#pragma comment(lib, "odbc32.lib")
#include <stdio.h>
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
class ODBC
{
public:
	bool db_connect();
	void db_disconnect();
	const char* get_data_type_in_string(SQLSMALLINT dataType);
	const char* dataSourceName = "DB01_Server";
	const char* serverId = "KIM";
	const char* serverPw = "1234";
	SQLHENV hEnv = NULL;	// Environment Handle
	SQLHDBC hDbc = NULL;	// Connection Handle
};

