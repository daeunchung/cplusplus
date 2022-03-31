#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, x;
int arr[17];

bool desc(int a, int b) {
    return a > b;
}
int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> x;
            if (x < 5) arr[j]++;
        }
    }
    sort(arr, arr + 17, desc);
    cout << N - arr[0] << '\n';
    return 0;
}

//
//4 3 1
//
//9 2 4
//8 4 3
//3 5 2
//1 4 6
/// /
/// /
///   /
/// /
//2 3 3  손님 수 - (메뉴중에 / )가장 큰값




// main.js
function init() {

}

function updateTable(sortBy) {

}

// member.js
function getMemberList() {
    return[
    { name: "김소마", age : 13, registerDate : "2010-02-04" },
    { name: "이서준", age : 25, registerDate : "2012-02-11" },
    { name: "강하준", age : 28, registerDate : "2014-06-03" },
    { name: "김도윤", age : 21, registerDate : "2010-01-13" },
    { name: "박시우", age : 23, registerDate : "2014-08-24" },
    { name: "장은우", age : 19, registerDate : "2012-07-10" },
    { name: "최지안", age : 24, registerDate : "2012-05-30" },
    { name: "윤서아", age : 22, registerDate : "2016-06-11" },
    { name: "서하윤", age : 20, registerDate : "2010-11-07" },
    { name: "신서윤", age : 29, registerDate : "2012-02-10" },
    { name: "송하은", age : 27, registerDate : "2017-02-23" },
    ];
}

// style.css
html{
  font - size: 16px;
  font - family: "Open Sans", sans - serif;
}

h1{
  font - size: 60px;
  text - align: center;
}

p,
li{
  font - size: 16px;
  line - height: 2;
  letter - spacing: 1px;
}

body{
  background: #f9f9f9;
}

.container{
  margin: 0 8 %;
}

table.memberTable{
  margin - top: 16px;
  width: 100 %;
  border - width: 2px 0 2px 0;
  border - color: #464646;
  border - style: solid;

  border - collapse: collapse;
}

table.memberTable thead tr{
  background - color: #eaeaea;
  height: 48px;
}

table.memberTable thead tr th{
  box - sizing: border - box;
  border - bottom: 1px solid #bebebe;
}

table.memberTable tbody tr{
  height: 36px;
}

table.memberTable tbody tr : nth - child(odd) {
    background - color: white;
}

table.memberTable tbody tr : nth - child(even) {
    background - color: #f2f2f2;
}

table.memberTable tbody tr : hover{
  background - color: #e9e9e9;
}

table.memberTable tbody tr td{
  text - align: center;
  border - bottom: 1px solid #bebebe;
}

// index.html
<!DOCTYPE html>
<html>
<head>
<meta charset = "utf-8" / >
<meta name = "viewport" content = "width=device-width, initial-scale=1" / >

<title>회원< / title>
<link href = "styles/style.css" rel = "stylesheet" type = "text/css" / >
<script src = "scripts/main.js">< / script>
<script src = "scripts/member.js">< / script>
< / head>
<body>
<h1>회원 목록< / h1>

<div class = "container">
<div class = "sort_radio">
<label>
<input type = "radio" name = "sort" value = "name" checked / >
이름
< / label>

<label>
<input type = "radio" name = "sort" value = "age" / >
나이
< / label>

<label>
<input type = "radio" name = "sort" value = "register_date" / >
등록일
< / label>
< / div>

<table class = "memberTable" id = "memberTable">
<thead>
<tr>
<th>이름< / th>
<th>나이< / th>
<th>등록일< / th>
< / tr>
< / thead>
<tbody>< / tbody>
< / table>
< / div>

<script>
window.onload = () = > {
    init();
};
< / script>
< / body>
< / html>



https://eaxdxaebodjgs3zsmmsndbiyzmu3xqry.runner-forwarder-a-02.elice.io/?_=818822