#include "Item3.h"
#include "STACK.h"

// client

int isnum(char c) {
	return (c - '0' >= 0) && (c - '0' <= 9);
}

int isop(char c) {
	const char ops[4] = "+-*/";
	int i;
	for (i = 0; i < 4; i++) {
		if (ops[i] == c) {
			return 1;
		}
	}
	return 0;
}

int main() {
	// 算術式に含まれる数字と記号の数 (括弧は除く) の最大は100とする
	// 算術式全体の長さ (空白・括弧も含む) の最大は500とする
	// 異なる数値はすべて空白区切で入力されるとする
	// 括弧の有無はどちらでも良い

	int num = 0, x, y, ci;
	char c, str[500];

	STACKinit(100);
	scanf("%[^\n]s", str);

	for (ci = 0; ci < strlen(str); ci++) {
		c = str[ci];
		num = 0;
		if (c == '(' || c == ')' || c == ' ') {
			// 括弧や空白は無視
			continue;
		}
		if (isnum(c)) {
			// 数字の場合、数値全体を見終わるまでciを進めてstackに数値を積む
			int i;
			for (i = 0; isnum(c); i++) {
				num *= 10;
				num += c - '0';
				ci++;
				c = str[ci];
				if (ci >= strlen(str)) {
					break;
				}
			}
			STACKpush(num);
		}
		if (isop(c)) {
			// 演算記号の場合、stackから直前の2つの数値を取り出して演算結果をstackに積む
			y = STACKpop();
			x = STACKpop();
			switch (c) {
			case '+':
				STACKpush(x + y);
				break;
			case '-':
				STACKpush(x - y);
				break;
			case '*':
				STACKpush(x * y);
				break;
			case '/':
				STACKpush(x / y);
				break;
			}
		}
	}

	printf("%d\n", STACKpop());

	STACKfree();
	return 0;
}