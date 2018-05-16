#include<map>
#include <iostream>

using namespace std;

const map<char, int> symbls_nubrs = {	{ '\\',0},{'!',1},{'#',2},{'$',3},{'%',4},{'&',5},{'\'',6 },{ '(',7 },{ ')',8 },{ '-',9 },
							{ '0',10 },{ '1',11 },{ '2',12 },{ '3',13 },{ '4',14 },{ '5',15 },{ '6',16 },{ '7',17 },{ '8',18 },{ '9',19 },
							{ '@',20 },{ 'A',21 },{ 'B',22 },{ 'C',23 },{ 'D',24 },{ 'E',25 },{ 'F',26 },{ 'G',27 },{ 'H',28 },{ 'I',29 },
							{ 'J',30 },{ 'K',31 },{ 'L',32 },{ 'M',33 },{ 'N',34 },{ 'O',35 },{ 'P',36 },{ 'Q',37 },{ 'R',38 },{ 'S',39 },
							{ 'T',40 },{ 'U',41 },{ 'V',42 },{ 'W',43 },{ 'X',44 },{ 'Y',45 },{ 'Z',46 },{ '^',47 },{ '_',48 },{ '`',49 },
							{ '{',50 },{ '}',51 },{ '~',52 } };//все символы с их номерами в лексиграфическом порядке (чтобы потом по символу получать его номер)

const char numbrs_symbls[] = "\\!#$%&'()-0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`{}~";//массив символов в лексографическом порядке (чтобы потом по номеру получать его символ)

const int SYMBOLS_COUNT = 53;

struct letters_tree {
	letters_tree* next_let[SYMBOLS_COUNT];//для каждого символаможет быть 53 варианта следующих символов, тоесть 53 листа
	bool is_end;//является ли буква последней в названии дирректории
}letters[40000];//всего максимум букв может быть 500*80

int counter = 1;//счётчик для letters

void create_tree(char *path) {
	letters_tree *current = &letters[0];
	int path_len = strlen(path);

	for (int i = 0; i < path_len; i++) {
		int let_num = symbls_nubrs.find(path[i])->second;
		if (current->next_let[let_num] == NULL) {
			current->next_let[let_num] = &letters[counter];
			counter++;
		}
		if (path[i] == '\\') {
			current->is_end = true;
		}
		current = current->next_let[let_num];
	}
	current->is_end = true;
}

char word_buffer[80];
void print_tree(letters_tree* current, int spaces) {
	for (int i = 0; i < SYMBOLS_COUNT; i++) {
		if(current->next_let[i]){
			int current_len = strlen(word_buffer);
			word_buffer[current_len++] = numbrs_symbls[i];//записываем в word_buffer следующий символ
			
			if (current->next_let[i]->is_end) {
				for (int j = 0; j < spaces; j++) {//делаем соответствующий отступ
					cout << " ";
				}

				//печатаем слово
				int current_pos = current_len;
				while (word_buffer[current_pos] != '\\' && current_pos != 0){//ищем начало слова
					current_pos--;
				}
				if (word_buffer[current_pos] == '\\') {//начинаем после черты
					current_pos++;
				}

				for (int j = current_pos; j < current_len; j++) {
					cout << word_buffer[j];
				}
				cout << endl;
			}
			if (numbrs_symbls[i] == '\\') {//переходим к следущей букве
				print_tree(current->next_let[i], spaces + 1);
			}else{
				print_tree(current->next_let[i], spaces);
			}
			word_buffer[--current_len] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;

	memset(letters, 0, sizeof(letters));

	char path[80];
	for (int i = 0; i < n; i++) {
		cin >> path;
		create_tree(path);
	}	

	letters_tree *start = &letters[0];
	print_tree(start,0);
	return 0;
}