//统计文本文件的所有单词（每个单词不包括空格及跨行，单词由字符序列构成且不区分大小写），字典顺序排列
//统计每个单词在文本文件中出现的总次数、频度（总次数/所有单词出现次数之和）
//检索输出某单词在文本文件中首次出现的行号和位置
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LEN 30
#define TEXT_CONTENT 50
#define TEXT_WORD 50
#define WORD_NUM 20

typedef struct list_word {
  char word[WORD_NUM]; //记录这个单词
  float frequency;       //该单词的频度
  int tag; // tag == 1(这个结构体有记录信息) tag == 0(无信息)
  int total;  //每个单词出现的总量
  int order, row; //row 为行，order 为当前行的第几个单词
} List_word;

int statistics_file_word(List_word lword[], FILE *fp); //统计文本文件的所有单词 频度 首次出现位置
void sorting(List_word lword[], FILE *fp, int sum); //字典排序

int main() {
  int total_word_num; // 是所有单词种类
  List_word lword[TEXT_WORD];

  //对结构体数组进行初始化
  int i = 0;
  while (i < TEXT_WORD) {
    lword[i].tag = 0;
    lword[i].total = 0;
    i++;
  }

  // open file
  char file_name[FILE_NAME_LEN];
  printf("请输入文件名(文件内字符数小于%d)：\n", FILE_NAME_LEN);
  scanf("%s", file_name);
  FILE *fp = fopen(file_name, "r");
  if (fp == NULL) {
    printf("打开文件失败。");
    exit(-1);
  }

  total_word_num = statistics_file_word(lword, fp);
  sorting(lword, fp, total_word_num);

  return 0;
}


int statistics_file_word(List_word lword[], FILE *fp) {
  int i = 0, loc = 0, // loc 为当前单词记录到的位置，i 计数结构体(单词的总数),
      sum = 0,          // 是所有单词出现的总次数
      n, m = 0;         // n 子串，m 主串
  char c[WORD_NUM]; //子串
  char a[TEXT_CONTENT]; //主串
  int row = 0, order = 0;

  while (1) {
    n = 0;
    if (a[m - 1] == '\n') {
      m = 0;
      row++;
      order = 0;
    }
    if ((c[n] = fgetc(fp)) == -1 || a[m - 1] == -1)
      break;
    else
      a[m] = c[n];

    while (c[n] != ' ' && c[n] != '\n') {
      n++, m++;
      // a[m] = c[n] = fgets(fp);
      if ((a[m] = c[n] = fgetc(fp)) == -1)
        break;
    }
    c[n] = '\0';
    i = 0; //新输入的单词和已输入的挨个比较
    while (lword[i].tag == 1) {
      if (strcmp(c, lword[i].word) == 0) { //有匹配单词
        lword[i].total++;
        sum++;
        i = loc; // 目的跳出循环
        loc--;   //使重复的单词不再进入结构体中
      }
      i++;
    }
    //没有匹配单词
    if (lword[loc].tag == 0) {
      strcpy(lword[loc].word, c);
      lword[loc].tag = 1;
      lword[loc].total++;
      sum++;
      lword[loc].order = order;
      lword[loc].row = row;
    }
    loc++;

    order++;
    m++;
  }

  //计算频度
  for (i = 0; i < loc; i++) {
    lword[i].frequency = lword[i].total * 1.0 / sum;
  }
  return loc;
}

void sorting(List_word lword[], FILE *fp, int sum) {
  List_word temp;
  int i_1 = 0, i_2 = 0, j = 0;
  for (; i_1 < sum; i_1++) {
    for (; i_2 < sum; i_2++) {
      if (strcmp(lword[i_1].word, lword[i_2].word) > 0) {
        temp = lword[i_1];
        lword[i_1] = lword[i_2];
        lword[i_2] = temp;
      }
    }
  }
}