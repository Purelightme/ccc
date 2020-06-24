//
// Created by purelightme on 2020/6/24.
//

#include <mysql.h>
#include <stdio.h>

int main(int argc, char **argv) {
    MYSQL *conn;
    conn = mysql_init(NULL);
    MYSQL_RES *result;
    int num_fields;
    MYSQL_ROW row;
    int i;
    MYSQL_FIELD *field;

    if (conn == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_real_connect(conn, "127.0.0.1", "root",
                           "root", NULL, 0, NULL, 0) == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_query(conn, "drop database  if exists testdb")) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_query(conn, "create database testdb")) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_query(conn, "use testdb")) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    if (mysql_query(conn, "create table users(id int auto_increment,name varchar(255),primary key(id))")) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }
    mysql_query(conn, "insert into users(name) values('scl1')");
    mysql_query(conn, "insert into users(name) values('scl2')");
    mysql_query(conn, "insert into users(name) values('scl3')");
    mysql_query(conn, "insert into users(name) values('scl4')");
    mysql_query(conn, "insert into users(name) values('scl5')");
    mysql_query(conn, "insert into users(name) values('scl6')");
    mysql_query(conn, "insert into users(name) values(NULL)");
    mysql_query(conn, "select * from users");
    result = mysql_store_result(conn);
    num_fields = mysql_num_fields(result);
    while (row = mysql_fetch_row(result)) {
        for (i = 0; i < num_fields; i++) {
            if (i == 0) {
                while (field = mysql_fetch_field(result)) {
                    printf("%s ", field->name);
                }
                printf("\n");
            }
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
    mysql_free_result(result);
    mysql_close(conn);
    return 0;
}