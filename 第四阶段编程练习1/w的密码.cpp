/*****
����
    ����һ����Ϣ��Ҫ����������, k1, k2 �� k3���ַ�[a-i] ���һ��, [j-r] �ǵڶ���, ���������ַ� ([s-z] ���»���)��ɵ����顣 ����Ϣ������ÿ����ַ�����ѭ���������ƶ�ki��λ�á� ÿ���е��ַ�ֻ���Լ����е��ַ����ɵĴ����ƶ������ܵĹ��̾���ÿ���е��ַ����Լ����ڵ�����ѭ���������ƶ�ki��λ�á�
    ���������Ϣ the_quick_brown_fox ��ki �ֱ�Ϊ 2, 3 �� 1�����м��ܡ����ܺ��� _icuo_bfnwhoq_kxert����ͼ��ʾ���������ܵĹ��̡�
    �۲�����[a-i]�е��ַ������Ƿ���{i,c,b,f,h,e}��������Ϣ�е�λ��Ϊ{2,3,7,8,11,17}����k1=2����һ�κ�, ����λ���е��ַ����{h,e,i,c,b,f}���±���ʾ�˾������е�һ���ַ���ת�õ����м��ַ�����Ȼ�������еڶ��飬��������ת���м��ַ�������һ���б任�ַ�����Ӱ�����������ַ���λ�á�
��������
    �������һ���������ݡ�ÿ����ǰ��һ�а����������� k1, k2 �� k3��������һ�м�����Ϣ����������һ����������0��ɵġ�
�������
    ����ÿ��������ݣ����������ǰ���ַ�����
��������
    2 3 1
    _icuo_bfnwhoq_kxert
    1 1 1
    bcalmkyzx
    3 7 4
    wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
    2 4 3
    cjvdksaltbmu
    0 0 0
�������
    the_quick_brown_fox
    abcklmxyz
    the_quick_brown_fox_jumped_over_the_lazy_dog
    ajsbktcludmv
*****/

#include <cstring>
#include <iostream>
using namespace std;

#define MAX_LEN 110
#define LARGE_INT_VAL 100000

int main()
{
	char s[MAX_LEN] = "\0", s1[MAX_LEN] = "\0", s2[MAX_LEN] = "\0", s3[MAX_LEN] = "\0";
	int a = 0, b = 0, c = 0;
	while (cin >> a >> b >> c && a)
    {
		cin.get();
		cin.getline(s, MAX_LEN);
		int idx1 = 0, idx2 = 0, idx3 = 0;
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
			if (s[i] >= 'a' && s[i] <= 'i')
				s1[idx1++] = s[i];
			else if (s[i] >= 'j' && s[i] <= 'r')
				s2[idx2++] = s[i];
			else
				s3[idx3++] = s[i];
		int idx21 = 0, idx22 = 0, idx23 = 0;
		for (int i = 0; i < l; ++i)
			if (s[i] >= 'a' && s[i] <= 'i')
				s[i] = s1[(idx21++ - a + LARGE_INT_VAL * idx1) % idx1];
			else if (s[i] >= 'j' && s[i] <= 'r')
				s[i] = s2[(idx22++ - b + LARGE_INT_VAL * idx2) % idx2];
			else
				s[i] = s3[(idx23++ - c + LARGE_INT_VAL * idx3) % idx3];
		cout << s << endl;
	}
	return 0;
}
