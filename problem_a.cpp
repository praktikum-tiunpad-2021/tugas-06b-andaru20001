#include "problem_a.hpp"

using namespace strukdat::stack;

template <typename T>
int getMax(Stack<T> Top) {
    pointer<T> dump;
    if (isEmpty(Top)){
        return 0;
    }
    else{
        int max = 0;
        while(!(isEmpty(Top))){
            if (max > peek(Top)){
                max = peek(Top);
            }
            
            pop(Top, dump);
        }
        return max;
    }
    
}

//Membuat fungsi-fungsi untuk mempermudah pengerjaan fungsi getEqualStack
template <typename T>
int sumElement(Stack<T> Top){
    pointer<T> temp = Top->next;
    int sum = 0;
    while (temp != nullptr)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return sum;
}

template <typename T>
int getEqualStack(Stack<T> Top1, Stack<T> Top2, Stack<T> Top3)
{
    if (isEmpty(Top1) || isEmpty(Top2) || isEmpty(Top3)){
        return 0;
    }
    else{
        pointer<T> delTop;
        int sum1 = 0;
        int sum2 = 0;
        int sum3 = 0;
        int max = 0;
        bool equal = 0;

        while (equal != 1){
            sum1 = sumElement(Top1);
            sum2 = sumElement(Top2);
            sum3 = sumElement(Top3);
        
            if (sum1 > sum2){
                if (sum1 > sum3){
                    max = 1;
                }
                else{
                    max = 3;
                }
            }
            else{
                if (sum2 > sum3){
                    max = 2;
                }
                else{
                    max = 3; 
                }
            }

            switch(max){
                case 1:
                    pop(Top1, delTop);
                    sum1 -= delTop->data;
                    break;
                case 2:
                    pop(Top2, delTop);
                    sum2 -= delTop->data;
                    break;
                case 3:
                    pop(Top3, delTop);
                    sum3 -= delTop->data;
                    break;
            }

            if (sum1 == sum2 && sum2 == sum3){
                break;
            }
        }

        return sum1;
    }
}

template <typename T>
bool isBracketBalanced(std::string expression)
{
    Stack<T> stringElement;
    pointer<T> dump;
    createStack(stringElement);
    for (int i=expression.length(); i>=0; i--){
        pointer<T> newElement;
        createElement(newElement, expression[i]);
        push(stringElement, newElement);
    }

    if (isEmpty(stringElement)){
        return false;
    }
    else{
        bool check = true;
        int bracketCheck = 0;
        int bracketCheck2 = 0;
        int last = 0;

        while(!(isEmpty(stringElement))){
            bracketCheck = peek(stringElement);
            switch(bracketCheck){
                case 40:
                    bracketCheck2 = 41;
                    break;
                case 91:
                    bracketCheck2 = 93;
                    break;
                case 123:
                    bracketCheck2 = 125;
                    break;
            }

            last = lastNode(stringElement);
            if (last != bracketCheck2){
                check = false;
                break;
            }
            else{
                pop(stringElement, dump);
            }
        }

        return check;
    }
}