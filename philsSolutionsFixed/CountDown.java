//this program outputs all the words of equal longest length that can be formed with the selection of letters
import java.util.*;
public class CountDown{
    public static void main(String[] args){FileIO reader = new FileIO();
        String[] contents = reader.load("dictionary.txt");
        Scanner myScanner = new Scanner(System.in);
        System.out.println("Enter the string of random letters");
        String input = myScanner.nextLine();
        int biggest = 0;
        ArrayList<String> myList = new ArrayList<String>();
        for (int i = 0; i< contents.length; i++){
            int length = check(input,contents[i]);
            //the reason for the substring above is that each entry in the contents array seems to include the return character and we don't want to count this
            if(length>biggest){
                biggest=length;
                myList.clear();
                myList.add(contents[i]);
            }else if(length==biggest){
                myList.add(contents[i]);
            }
        }
        System.out.println("The longest word that can be formed is one with "+biggest+" letters:");
        for(int i=0;i<myList.size();i++){
            System.out.println(myList.get(i));
        }
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
