/*****
描述
    加密一条信息需要三个整数码, k1, k2 和 k3。字符[a-i] 组成一组, [j-r] 是第二组, 其它所有字符 ([s-z] 和下划线)组成第三组。 在信息中属于每组的字符将被循环地向左移动ki个位置。 每组中的字符只在自己组中的字符构成的串中移动。解密的过程就是每组中的字符在自己所在的组中循环地向右移动ki个位置。
    例如对于信息 the_quick_brown_fox 以ki 分别为 2, 3 和 1蔼进行加密。加密后变成 _icuo_bfnwhoq_kxert。下图显示了右旋解密的过程。
    观察在组[a-i]中的字符，我们发现{i,c,b,f,h,e}出现在信息中的位置为{2,3,7,8,11,17}。当k1=2右旋一次后, 上述位置中的字符变成{h,e,i,c,b,f}。下表显示了经过所有第一组字符旋转得到的中间字符串，然后是所有第二组，第三组旋转的中间字符串。在一组中变换字符将不影响其它组中字符的位置。
关于输入
    输入包括一到多组数据。每个组前面一行包括三个整数 k1, k2 和 k3，后面是一行加密信息。输入的最后一行是由三个0组成的。
关于输出
    对于每组加密数据，输出它加密前的字符串。
例子输入
    2 3 1
    _icuo_bfnwhoq_kxert
    1 1 1
    bcalmkyzx
    3 7 4
    wcb_mxfep_dorul_eov_qtkrhe_ozany_dgtoh_u_eji
    2 4 3
    cjvdksaltbmu
    0 0 0
例子输出
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
