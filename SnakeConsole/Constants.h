#pragma once
const int scr_width = 40;
const int scr_heigth = 22;

const int heigthMap = 20;
const int widthMap = 40;
const char wall = '#';
const char head = '@';
const char apple = '*';
const char tail_c = '+';
enum Direction { Left, Rigth, Up, Down };
enum State { Life, Death };
const int maxLengthTail = 680;