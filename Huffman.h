#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define  N 256
#define Maxsize 80
#define  SOME 1
#define Empty 0
#define FULL -1
#define MAX 1000
typedef unsigned long int WeightType;
typedef unsigned char MyType;
typedef struct //哈夫曼树
{
    MyType ch; //存字符
    WeightType weight ; /* 用来存放各个结点的权值*/
    int  parent, LChild,RChild ; /*指向双亲、孩子结点的指针*/
}HTNode, HTNODE;

typedef struct //队列
{
    int tag;
    int front;
    int rear;
    MyType length;
    char elem[Maxsize];
}SeqQueue;
void writeFile();
void printHFM(HTNode *ht,int n);
void code(char **hc,int n,unsigned char *ch);
int InitQueue(SeqQueue *Q);
int In_seqQueue(SeqQueue *Q,char x);
int Out_Queue(SeqQueue *Q,char *x);
void SelectMinTree(HTNode *ht,int n,int *k);
int SortTree(HTNode *ht);
char **CrtHuffmanCode(HTNode *ht,short LeafNum);
HTNode* CreatHFM(FILE *fp,short *n,WeightType *FileLength);
MyType GetBits(SeqQueue *Q);
void MaxMinLength(FILE *File,HTNode *ht,char **hc,short NLeaf,MyType *Max,MyType *Min);
short CodeToFile(FILE *fp,char **hc,short n,SeqQueue *Q,MyType *length);
void Compress(char *filename);
void ToQueue(SeqQueue *Q,MyType ch);
void UnCompress(char *, char *);
void writeFile();
void code(char **hc,int n,MyType *ch);
void printHFM(HTNode *ht,int n);
#endif // HUFFMAN_H
