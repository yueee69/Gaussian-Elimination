#include <iostream>
using namespace std;

const int N = 50; //宣告二維陣列的常數 可更改大小

void G()
{
	int x, a, b, nx = 0, ny = 1, A, sum = 0, sumA, sumB = 0;
	//x為輸入未知數係數與常數的宣告 a為輸入n列數 b為行數(固定為a+1)
	// nx ny A sum sumA sumB為每行互相消去的宣告 到時會詳細介紹
	char s[] = { "abcdefghijklmnoprstuvwxyz" };//印出未知數的一為字元陣列
	double g[N][N] = {0}, r = 0, ansy = 0, ansx[] = { 0 };
	//g為存放增廣矩陣值的二維陣列 r為兩行將互加的商(第n行/第m行) ansx ansy為解未知數時的宣告 到時會詳細介紹
	int l = 2;//此處也是每行互相消去的宣告
	b = 3;
	cout << "列值=";
	cin >> a;//輸入列值
	b = a + 1;//行值(未知數+常數的數量)=列值+1
	cout << "一行有" << b << "個數字" << endl;
	for (int ap = 1; ap <= a; ap++) {//此處為計算需要輸入幾次值的迴圈 ap為列 bp為行
		for (int bp = 0; bp < b; bp++) {
			cin >> x;//共需要輸入a*b次
			g[ap][bp] = x;//將輸入的值存到二維陣列g中
		}
	}
	cout << endl << "得出的矩陣是: " << endl;
	for (int ap = 1; ap <= a; ap++) {//此處是印出輸入好的增廣矩陣
		for (int bp = 0; bp < b; bp++)
		{
			if (ap == 1 && bp == 0)
				cout << "「 ";//這裡的if-else結構 是為了還原矩陣的"［"
			else if (ap == a && bp == 0)
				cout << "﹂ ";
			else if (bp == 0)
				cout << "│  ";
			cout << g[ap][bp];//輸出入的數值
			if (b - bp - 1 != 0) cout << s[bp] << " ";//這裡是判斷數值正負 避免有+(-1)的情況發生
			if (g[ap][bp + 1] >= 0 && b > bp + 2) cout << "+";//不是負且下一項不是常數 輸出+
			else if (b == bp + 2) cout << "=";//常數前印出=

			if (ap == 1 && bp == b - 1 && bp - b - 1 != 0)
				cout << "﹁\t";//這裡的if-else結構 是為了還原矩陣的"］"
			else if (a == ap && bp == b - 1)
				cout << " 」\t";
			else if (bp == b - 1)
				cout << " │\t";
		}
		cout << endl;
	}
	sumB = sumA = a - 1;//sumA sumB為一列要計算幾次的宣告 詳情見下
	for (A = 1; A < a; A++) {//這裡是計算r要計算幾次 要計算的次數公式如下:1+2+3..+a-1
		sum += A;//將算出的數字存入sum
	}
	for (int nr = 1; nr <= sum; nr++) {//此處迴圈將重複sum次
		r = -(g[l][nx] / g[nx + 1][nx]);
	//r為兩行將互加的商(第n行/第m行) nx為控制列的數
	//(舉例:如果是第一次進入此迴圈 r=-(g[2][0]/g[1][0]) 也就是第一列第二個數除第一列第一個數)
		for (int t = 0; t < b; t++) {//兩行互加的迴圈
			g[l][t] += r * g[nx + 1][t];//此處會先算出該行*r的每個值 加回原本行的每個值
	//(舉例 g[2][0]*r+g[1][0] 也就是第一列第二個數*r加到第一列第一個數 該行每個值都是如此)
		}
		l++;//控制在第n列時 要從n+1行開始計算
		if (nr == sumB) {
			nx++;
			sumA--;
			sumB = sumB + sumA;
	//這裡整個if一起講 sumB為計算到該列的最底了 就往內推進一列(nx+1) 並計算下一列需要計算r的次數
	//假設此為三元 第一列需要由2 3行*r後加回 第二列需要第3行*r後加回 以此類推 
		}
		if (l == a + 1) l = 2 + nx;//從下一列的第n+1行開始計算
	}
	cout << endl << "得出的矩陣是: " << endl;
	for (int ap = 1; ap <= a; ap++) {//這裡印出消去好的增廣矩陣
	//注意！只有消去 並沒有解未知數
	//其實這跟上一個印出矩陣的程式一模一樣 也可以寫成副程式呼叫
		for (int bp = 0; bp < b; bp++)
		{
			if (ap == 1 && bp == 0)
				cout << "「 ";//這裡的if-else結構 是為了還原矩陣的"［"
			else if (ap == a && bp == 0)
				cout << "﹂ ";
			else if (bp == 0)
				cout << "│  ";
			cout << g[ap][bp];
			if (b - bp - 1 != 0) cout << s[bp] << " ";//這裡是判斷數值正負 避免有+(-1)的情況發生
			if (g[ap][bp + 1] >= 0 && b > bp + 2) cout << "+";//不是負且下一項不是常數 輸出+
			else if (b == bp + 2) cout << "=";//常數前印出=

			if (ap == 1 && bp == b - 1 && bp - b - 1 != 0)
				cout << "﹁\t";
			else if (a == ap && bp == b - 1)
				cout << " 」\t";//這裡的if-else結構 是為了還原矩陣的"］"
			else if (bp == b - 1)
				cout << " │\t";
		}
		cout << endl;
	}
	if (a >= 2 && g[a][a - 1] != 0) {//開始判斷解的數量 如果最後一個未知數!=0 則成立) 
		cout << endl << "唯一解" << endl;
		int z = 0;//z為計算第n行需要代入幾個未知數的判斷式之一
		for (int x = a; x >= 1; x--) {//解未知數的迴圈
			ansx[x] = (g[x][a] - ansy) / g[x][x - 1];//ansx為存入已解未知數的浮點數陣列 此行將求出未知數
			z++;//
			ansy = 0;//ansy將代回去的常數加總 此處因為每行係數並不會一樣 故需要初始化
			for (int y = a; y > a - z; y--) {//將解出來的未知數代回上面一行
	//a y z為計算本行需要代回幾個未知數 公式是:第n行需要代回n-1個未知數
				ansy += ansx[y] * g[x - 1][y - 1];//將代回去的常數加總 並"減"常數項(因為移項)
			}
			cout << s[x - 1] << "=" << ansx[x] << " ";//印出解！
		}
	}
	else if (g[a][a] != 0) {//根據上面的判斷式 如果最後一個未知數=0"且"常數!=0 則成立 
		cout << endl << "無解！" << endl;
	}
	else {//如果最後一個未知數=0"且"常數=0
		cout << endl << "無限解" << endl;

	}system("pause");
}

//這個程式從開始構思到完成 都沒有參考別人的作品(一是又要花時間讀懂 二是沒成就感)
//耗時大概..10小時(打註解2小時)

int main()
{
	G();
}

