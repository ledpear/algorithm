#include <stdio.h>
#include <string.h>

char* my_strtok(char* str, const char* delimiters) {
	static char* pCurrent;
	char* pDelimit;

	if (str != NULL)pCurrent = str;
	else str = pCurrent;

	if (*pCurrent == NULL) return NULL;

	//문자열 점검
	while (*pCurrent)
	{
		pDelimit = (char*)delimiters;

		while (*pDelimit) {
			if (*pCurrent == *pDelimit) {
				*pCurrent = NULL;
				++pCurrent;
				return str;
			}
			++pDelimit;
		}
		++pCurrent;
	}
	// 더이상 자를 수 없다면 NULL반환
	return str;
}

int main() {
	char str[] = "MY NAME IS TOM"; //대상 문자열 
	char *temp = strchr(str, ' '); //공백을 기준으로 문자열 자르기

	while (temp != NULL) { //널이 아닐때까지 반복
		++temp;
		printf("%s\n", temp); // 출력
		temp = strchr(temp, ' ');	//널문자를 기준으로 다시 자르기
	}
}