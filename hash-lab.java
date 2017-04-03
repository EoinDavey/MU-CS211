      
class Solution{
    
    HashTable mytable = new HashTable();
    int size = 0;

    public Solution(HashTable input){
        
        mytable = input;
        size = input.size;
        //this is the constructor
    }
    
    public void fill(String[] array){
         for(int i = 0; i < size; i++){
             mytable.set(i,"");
         }
         for(int i=0; i<array.length;i++){
            int index = getHashKey(array[i]);
            int doubleHash = getDoubleHashKey(array[i]);
            while(!mytable.check(index,"")){
                index=index+doubleHash;
                index=index%size;
            }
            mytable.set(index,array[i]);
         }
    }
    
    public int getHashKey(String word){
        long hash = 0;
        for(int i = 0; i < word.length(); i++){
            hash+=((long)word.charAt(i));
            hash+=(hash<<10);
            hash^=(hash>>6);
        }
        hash+=(hash<<3);
        hash^=(hash >> 11);
        hash+=(hash<<15);
        Random r = new Random(hash);
        return ((r.nextInt() % size) + size) % size;
    }
    
    public int getDoubleHashKey(String word){
        int p = 26407;
        long hash = 0;
        for(int i = 0; i < word.length(); i++){
            hash = (hash*33) ^ ((int)word.charAt(i));
        }
        Random r = new Random(hash);
        return p - ((r.nextInt() % p) + p) % p;
    }
     
    public int find(String word){
         int index = getHashKey(word);
         while(!mytable.check(index,word)){
             index=index+getDoubleHashKey(word);
             index=index%size;
        }
        return index;
    }  
}
