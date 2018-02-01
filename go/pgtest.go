package main

import (
	"database/sql"
	"fmt"
	_ "github.com/lib/pq"
)

func checkErr(err error) {
	if err != nil {
		fmt.Println(err)
	}
}

func main() {

	//插入数据
	db, err := sql.Open("postgres", "host=127.0.0.1 port=5432 user=postgres password=1234567 sslmode=disable")
	checkErr(err)
	stmt, err := db.Prepare("INSERT INTO PUBLIC.user(name,age) VALUES ($1,$2) RETURNING id")
	checkErr(err)
	res, err := stmt.Exec("jack", 23)
	//受影响行数
	id, err := res.RowsAffected()
	checkErr(err)
	fmt.Println(id)

	//修改数据
	stmt, err = db.Prepare("UPDATE  PUBLIC.user set name=$1 where id=$2")
	checkErr(err)
	res, err = stmt.Exec("hellen", 1)
	checkErr(err)
	affect, err := res.RowsAffected()
	checkErr(err)
	fmt.Println(affect)

	//查询数据
	rows, err := db.Query("SELECT * FROM PUBLIC.user")
	checkErr(err)
	for rows.Next() {
		var id int
		var name string
		var age int
		err = rows.Scan(&id, &name, &age)
		checkErr(err)
		fmt.Printf("%d  %s  %d\n", id, name, age)
	}

	//删除数据
	stmt, err = db.Prepare("DELETE FROM PUBLIC.user where id=$1")
	checkErr(err)

	res, err = stmt.Exec(10)
	res, err = stmt.Exec(11)
	res, err = stmt.Exec(12)
	checkErr(err)
	affect, err = res.RowsAffected()
	fmt.Println(affect)
	db.Close()

}
