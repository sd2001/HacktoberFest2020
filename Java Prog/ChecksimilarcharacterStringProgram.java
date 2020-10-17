import java.util.*;
 
public class same{
 
static boolean allcharacterssame(String s1)
{
    int n = s1.length();
    for (int i = 1; i < n; i++)
        if (s1.charAt(i) != s1.charAt(0))
            return false;
         
    return true;
}
 
    static public void main (String[]args){
        String s = "rrrrrr";
    if (allcharacterssame(s))
        System.out.println("Yes");
    else
        System.out.println("No");
         
    }
}