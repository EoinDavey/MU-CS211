public class Main{
    public static void main(String[] args){
     int biggest = 0;
     for (int i = 0; i< contents.length; i++){
         int length = check(input,contents[i].substring(0,contents[i].length()-1));
         if(length>biggest){
             biggest=length;
         }
     }
     System.out.println(biggest);
 }

 public static int check(String letters, String word){
     for(int i=0; i<word.length(); i++){
         if(!letters.contains(""+word.charAt(i))){
             return -1;
         }
             letters=letters.replaceFirst(""+word.charAt(i)," ");
         }
         return word.length();
     }
}
