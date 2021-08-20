#include <stdio.h>
#include <string.h>

char* my_strtok(char* str, const char* delimiters) {
	static char* pCurrent;
	char* pDelimit;

	if (str != NULL)pCurrent = str;
	else str = pCurrent;

	if (*pCurrent == NULL) return NULL;

	//���ڿ� ����
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
	// ���̻� �ڸ� �� ���ٸ� NULL��ȯ
	return str;
}

int main() {
	char str[] = "MY NAME IS TOM"; //��� ���ڿ� 
	char *temp = strchr(str, ' '); //������ �������� ���ڿ� �ڸ���

	while (temp != NULL) { //���� �ƴҶ����� �ݺ�
		++temp;
		printf("%s\n", temp); // ���
		temp = strchr(temp, ' ');	//�ι��ڸ� �������� �ٽ� �ڸ���
	}
}