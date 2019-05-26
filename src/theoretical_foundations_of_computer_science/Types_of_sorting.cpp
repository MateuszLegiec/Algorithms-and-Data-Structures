
using namespace std;


void bubblesort(int tab[],int tabLength){

    for(int trans=0;trans<tabLength;trans++){
        for(int i=0;i+1<trans;i++){
            if(tab[i]>tab[i+1])
                swap(tab[i],tab[i+1]);
        }
    }
}

int maxIndex(int tab[],int tabLength){

    int index=0;

    for(int i=1;i<tabLength;i++){
        if(tab[i]>tab[index])
            index=i;
    }

    return  index;
}

void selectionSort(int tab[],int tabLength){

    for(int trans=tabLength;trans>1;trans--)
        swap(tab[maxIndex(tab,trans)],tab[trans-1]);

}

void insertSort(int tab[],int tabLength){

    int temp,i;

    for(int index=1;index<tabLength;index++){
        temp=tab[index];
        for(i=index-1;i>=0  &&  tab[i]>temp;i--)
            tab[i+1]=tab[i];
        tab[i+1]=temp;
    }
}
