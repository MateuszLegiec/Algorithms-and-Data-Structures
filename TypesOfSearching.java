/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package typesofsearching;

/**
 *
 * @author MateuszLegiec
 */
public class TypesOfSearching {
   
   
    public int seekrek(int searched,int firstIndex,int lastIndex,int tab[]){
        int index;
        if(firstIndex==lastIndex){
            if(searched==tab[lastIndex])
                return lastIndex;
            return (-1);
        }
        index=(firstIndex+lastIndex)/2;
        if(searched>tab[index])
            return seekrek(searched,index+1,lastIndex,tab);
        return  seekrek(searched,firstIndex,index,tab);
    }

   
    public int seekbis(int searched,int tabLength,int tab[]){
        int index,l=0,result=tabLength;
        while(result>l){
            index=(l+result)/2;
            if(searched>tab[index])
                l=index+1;
            else
                result=index;
        }
        if(searched==tab[result])
            return  result;
        return (-1);
    }
    
    
    public int linearSeek(int searched,int tabLength,int tab[]){
        for(int i=0;i<tabLength;i++){
            if(tab[i]==searched)
                return i;
        }
        return (-1);
}
    
    
}










