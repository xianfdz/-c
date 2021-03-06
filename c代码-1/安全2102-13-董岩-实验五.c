/*在密码学中，恺撒密码（英语：Caesar cipher），或称恺撒加密、恺撒变换、
变换加密，是一种最简单且最广为人知的加密技术。它是一种替换加密的技术，明

文中的所有字母都在字母表上向后（或向前）按照一个固定数目进行偏移后被替换

成密文。向后移动的位数就是密钥，例如，密钥 k=3，则每个字母都会向前移动 3

位：a 会被替换为 d；b 会被替换成 e；依此类推。字母表末尾将回卷到字母表开

头。于是，w 会被替换为 z，x 会被替换为 a。 
请编写程序，要求输入密码和信息，然后京程序加密后输出密文，并设计解密
程序对密文进行解密。*/
#include<stdio.h>
#define N 30//N-1代表要加密的最大字符个数 
int main()
{
	int k,i,j;//k代表密钥 
	char ming[N],mi[N];//ming代表明文，mi代表密文 
	printf("请输入要加密的密钥：\nk=");
	scanf("%d",&k);//输入密钥 
	printf("请输入要加密的明文：\n");
	getchar();//清除缓冲区 
	gets(ming);//输入明文
	printf("加密后为：\n");
	for(i=0;i<N;i++)//for循环遍历明文所有字符 
	{
		if(ming[i]!=0&&ming[i]!=' ')//如果数组里的元素不是空格且不为零 ，则对其进行加密，否则不加密 
		{
			for(j=0;j<k;j++)// 遍历密钥，每次使明文字符向后移一位 
			{
				if(ming[i]=='z') ming[i]='a';//当字符为小写字母z且向后一位会超出字母表a到z的范围，则将该字符赋值为a 
				else if(ming[i]=='Z') ming[i]='A';//当字符为大写字母Z且向后移一位会超出字母表A到Z的范围，则将该字符赋值为A
				else ming[i]++; //当字符向后移一位未超过字母表范围，则将该字符向后移一位 
			}  
		}
	}
	puts(ming);//输出密文 
	printf("请输入要解密的密文：\n");
	gets(mi);
	printf("解密后为：\n");
	for(i=0;i<N;i++)//for循环遍历密文所有字符 
	{
		if(mi[i]!=0&&mi[i]!=' ')//如果数组里的元素不是空格且不为零 ，则对其进行解密，否则不解密
		{
			for(j=0;j<k;j++)// 遍历密钥，每次使密文字符向前移一位 
			{
				if(mi[i]=='a') mi[i]='z';//当字符为小写字母a且向前一位会超出字母表a到z的范围，则将该字符赋值为z
				else if(mi[i]=='A') mi[i]='Z';//当字符为大写字母A且向前移一位会超出字母表A到Z的范围，则将该字符赋值为Z 
				else mi[i]--; //当字符向前移一位未超过字母表范围，则将该字符向前移一位 
			}  
		}
	} 
	puts(mi);//输出明文 
}
