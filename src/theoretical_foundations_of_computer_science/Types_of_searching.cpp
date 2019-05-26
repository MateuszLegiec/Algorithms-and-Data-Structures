using namespace std;

int recursionSearching(int searched,int firstIndex,int lastIndex,int tab[]){

    if(firstIndex==lastIndex)
        return (searched==tab[lastIndex])?lastIndex:(-1);

    if(searched>tab[index])
        return recursionSearching(searched,(firstIndex+lastIndex)/2+1,lastIndex,tab);

    return  recursionSearching(searched,firstIndex,(firstIndex+lastIndex)/2,tab);
}

int bisectionSearching(int searched,int tabLength,int tab[]){

    int index,l=0,result=tabLength;

    while(result>l){

        index=(l+result)/2;
        if(searched>tab[index])
            l=index+1;
        else
            result=index;
    }

    return (searched==tab[result])?result:(-1);
}

int linearSearching(int searched,int tabLength,int tab[]){
    for(int i=0;i<tabLength;i++){
        if(tab[i]==searched)
            return i;
    }
    return (-1);
}
