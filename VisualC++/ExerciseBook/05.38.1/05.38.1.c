#include <stdio.h>
#include "SString.h"    //**��04 ��**//
#include "GList-HT.h"   //**��05 ����͹����**//

/*
 * ���������е�l���ԭ����(ͷβ�����洢��ʾ)
 */
void Algo_5_38_1(GList L, int d, int l);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
    SString S;
    
    printf("��������� L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGraph(L);
    
    printf("������� 2 ���ԭ����Ϊ��");
    Algo_5_38_1(L, 0, 2);
    printf("\n");

    return 0;
}


/*
 * ���������е�l���ԭ����(ͷβ�����洢��ʾ)
 */
void Algo_5_38_1(GList L, int d, int l) {
    int i = d;  // d�ĳ�ֵ��ֵΪ0
    
    if(L && l >= i) {
        if(L->tag == Atom) {
            // ��������
            if(l == i) {
                printf("%c ", L->Node.atom);
            }
        } else {
            Algo_5_38_1(L->Node.ptr.hp, i + 1, l);  // ��ͷָ��ָ����Ļ�������һ
            Algo_5_38_1(L->Node.ptr.tp, i, l);
        }
    }
}