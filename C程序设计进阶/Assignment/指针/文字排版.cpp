//
//  main.cpp
//  cpluspluscoursera
//
//  Created by JUNXIAO YI on 9/25/15.
//  Copyright (c) 2015 JUNXIAO YI. All rights reserved.
/*
 描述
 
 给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：
 
 每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。
 
 输入
 
 第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。
 
 输出
 
 排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。
 
 样例输入
 
 84
 One sweltering day, I was scooping ice cream into cones and told my four children they could "buy" acone from me for a hug. Almost immediately, the kids lined up to make their purchases. The three youngest each gave me a quick hug, grabbed their cones and raced back outside. But when my teenage son at the end of the line finally got his turn to "buy" his ice cream, he gave me two hugs. "Keep the changes," he said with a smile.
 样例输出
 
 One sweltering day, I was scooping ice cream into cones and told my fourchildren they could "buy" a cone from me for a hug. Almost immediately, the kidslined up to make their purchases. The three youngest each gave me a quick hug,grabbed their cones and raced back outside. But when my teenage son at the endof the line finally got his turn to "buy" his ice cream, he gave me two hugs."Keep the changes," he said with a smile.
 */

#include <iostream>
using namespace std;

int main(void)
{
    int n;  // 表示短文中单词的数目
    cin >> n;
    
    int max = 80 * n;   // 表示最多字符数
    char * str = new char[80 * n];
    
    cin.get();
    cin.getline(str, max);
    
    int wordstart = 0; // 设置当前单词的首字母位置
    int linestart = 0; // 设置当前行首字母位置
    
    for ( int count = 0; str[count] != '\0'; count++ )
    {
        if ( str[count+1] == ' ' || str[count+1] == '\0' )
        {
            if ( (count - linestart) > 79 && str[count+1] != '\0')
            {
                cout << '\n';
                linestart = wordstart;
            }
            else if ( wordstart != 0 )
                cout << ' ';
            
            for ( int i = wordstart; i <= count; i++ )
                cout << str[i];
            
            if ( str[count+1] != '\0' )
                wordstart = count + 2;
        }
    }
    
    return 0;
}