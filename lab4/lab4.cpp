#include <iostream>
#include <stdio.h>
using namespace std;
const int nmax=256;

int isInWord(int wordLen,char c, char word []){
    for(int i =0; i<wordLen; i++){
        if(word[i]==c){
            return 1;
        }
    }
    return 0;
}
void changeWord(int &wordLen,char word [],char newWord []){
    newWord[0] = word[0];
    int nc = 0;
    for(int i = 1; i<wordLen; i++){
        if(!isInWord(nc+1,word[i],newWord)){
            nc++;
            newWord[nc]=word[i];

        }
    }
    wordLen=nc;
}
//void changeWord2(int &wordLen,char word[]){
//    for (int i = 0; i < wordLen - 1; i++)
//        for (int j = i + 1; j < wordLen; j++)
//            if (word[i]==word[j])
//            {
//                for (int k = j; k < wordLen; k++)
//                    word[k]=word[k + 1];
//                wordLen--;
//                j--;
//            }
//
//}

int main() {
    int n;//число символов во входной строке
    int wc = 0;//число символов в выделенном слове
    char word[nmax];//выделенное слово
    char string[nmax];//входная строка
    char newWord[nmax];//новое слово
    char newString[nmax];//новая строка
    bool flag = false;//флаг наличия слова
    cin >> n;//вводим количество символов
    cin.ignore();//удаляет символ '\n' из потока
    gets_s(string, nmax);//вводим строку
    int slen = 0;//длина новой строки
    for (int i = 0; i < n; i++) {
        if ((string[i] >= '0' && string[i] <= '9') || (string[i] >= 'A' && string[i] <= 'Z') ||
            (string[i] >= 'a' && string[i] <= 'z')) {//проверяем, входит ли символ в слово
            word[wc] = string[i];//помещаем символ в слово
            wc++;//увеличиваем счетчик символов в слове
            flag = true;//слово найдено
        } else if (flag) {//если слово найдено, но был встречен разделитель
            changeWord(wc, word, newWord);//удаляем повторы из слова
            // changeWord2(wc,word);
            for (int k = 0; k <= wc; k++) {//копируем слово в итоговую строку
                newString[slen + k] = newWord[k];
            }
            slen += wc+1;//увеличиваем счетчик длины строки
            wc = 0;//обнуляем счетчик слова
            flag = false;
        }
    }
//для обработки последнего слова, после которого нет разделителя
    if (flag) {
        changeWord(wc, word, newWord);
        for (int k = 0; k <= wc; k++) {
            newString[slen+k] = newWord[k];
        }
        slen += wc+1;
    }
    if(slen<1){//проверка наличия слов в строке
        cout<<"No words"<<endl;
    }else {//вывод нового слова
        for (int i = 0; i < slen; i++) {
            cout << newString[i];
        }
    }
    return 0;



}