#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

int main(void)
{
    int x,un,flg=1;
    double a,b,c,d,t,st,ans=0;
    char p,q,ser;
    system("clear");
    srand((unsigned)time(NULL)); //実行するとするたびに異なる乱数が発生する「乱数を初期化する」
    printf("Please enter your lucky number in 1~5.>>> ");
    scanf("%d",&un);
    x = rand()%5+1; //1~5のどれか
    printf("Your fortune of today is");
    if(x == un){
        printf("\033[033m Great roll\033[m.\n\n");
    }
    else{
        printf(" commom.\n\n");
    }
    printf("###########################################################\n");
    printf("##         At first we do arithmetic operations          ##\n");
    printf("##                                                       ##\n");
    printf("##                    mode selection                     ##\n");
    printf("##   aaa:arithmetic operation  ff:function calculation   ##\n");
    printf("##                                                       ##\n");
    printf("##               In function calculation                 ##\n");
    printf("##         ex)   s30:sin30     c30:cos30                 ##\n");
    printf("##               t30:tan30     l10:log10(10)             ##\n");
    printf("##               S30:arcsin30  C30:arccos30              ##\n");
    printf("##               T30:arctan30  L10:loge(10)              ##\n");
    printf("##                                                       ##\n");
    printf("##                        qq:end                         ##\n");
    printf("###########################################################\n\n\n");
    scanf("%lf",&c);
    getchar(); //改行
    while(1){
        while(flg == 1){
            scanf("%c",&p); //演算子
            scanf("%lf",&d);
            switch(p){      //演算子判定
                case '+':
                    c += d;
                    break;
                case '-':
                    c -= d;
                    break;
                case '*':
                    c *= d;
                    break;
                case '/':
                    c /= d;
                    break;
            }
            ans = c;
            printf("\033[033m=%lf\n\033[m",ans);
            scanf("%c",&ser); //改行、もしくはモード選択。
            if(p ==  'q'){
                system("clear");
                return 0;
            }
            if(ser == 'f'){
                flg = 0;
                printf("taku\n");
                getchar();
                break;
            }
        }
        while(flg == 0){
            printf("erty\n");
            scanf("%c",&p); //演算子
            printf("cvbghnj\n");
            scanf("%c",&q); //関数の判定
            if(p == 'q'){
                system("clear");
                return 0;
            }
            scanf("%lf",&b);
            st = b*PI/180.0;
            if(p == '+'){
                if(q == 's'){
                    c += sin(st);
                }
                else if(q == 'c'){
                    c += cos(st);
                }
                else if(q == 't'){
                    c += tan(st);
                }
                else if(q == 'S'){
                    c += asin(st);
                }
                else if(q == 'C'){
                    c += acos(st);
                }
                else if(q == 'T'){
                    c += atan(st);
                }
                else if(q == 'l'){
                    c += log10(b);
                }
                else if(q == 'L'){
                    c += log(b);
                }
            }else if(p == '-'){
                if(q == 's'){
                    c -= sin(st);
                }
                else if(q == 'c'){
                    c -= cos(st);
                }
                else if(q == 't'){
                    c -= tan(st);
                }
                else if(q == 'S'){
                    c -= asin(st);
                }
                else if(q == 'C'){
                    c -= acos(st);
                }
                else if(q == 'T'){
                    c -= atan(st);
                }
                else if(q == 'l'){
                    c -= log10(b);
                }
                else if(q == 'L'){
                    c -= log(b);
                }
            }else if(p == '*'){
                if(q == 's'){
                    c *= sin(st);
                }
                else if(q == 'c'){
                    c *= cos(st);
                }
                else if(q =='t'){
                    c *= tan(st);
                }
                else if(q == 'S'){
                    c *= asin(st);
                }
                else if(q == 'C'){
                    c *= acos(st);
                }
                else if(q == 'T'){
                    c *= atan(st);
                }
                else if(q == 'l'){
                    c *= log10(b);
                }
                else if(q == 'L'){
                    c *= log(b);
                }
            }else if(p == '/'){
                if(q == 's'){
                    c /= sin(st);
                }
                else if(q == 'c'){
                    c /= cos(st);
                }
                else if(q == 't'){
                    c /= tan(st);
                }
                else if(q == 'S'){
                    c /= asin(st);
                }
                else if(q == 'C'){
                    c /= acos(st);
                }
                else if(q == 'T'){
                    c /= atan(st);
                }
                else if(q == 'l'){
                    c /= log10(b);
                }
                else if(q == 'L'){
                    c /= log(b);
                }
            }
            ans = c;
            printf("\033[033m=%lf\n\033[m",ans);
            scanf("%c",&ser);
            if(ser == 'a'){
                flg = 1;
                getchar();
                break;
            }
        }
    }
}
