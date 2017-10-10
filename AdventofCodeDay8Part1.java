/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package adventofcodeday8part1;

/**
 *
 * @author Matt's 2 in 1
 */

import java.io.*;
import java.util.*;

public class AdventofCodeDay8Part1 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        File file = new File("Your File here.txt");
        
        FileInputStream inputfile = null;
       
        String inputtostring;
        
        int readlength;

        //First, confirm that a filename has been specified.
        if(args.length != 1)
        {
            System.out.println("Usage: ShowFile AdventofCodeDay8Part1.txt");
            System.out.println();
        }
        
        //Attempt to open the file.
        try
        {
            inputfile = new FileInputStream(file);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Cannot open file.");
            return;
        }
        
        //At this point, the file is open and can be read from.
        //The following reads characters until EOF is reached.
        try
        {
            do
            {
                readlength = inputfile.read();
                
                if(readlength != -1)
                {
                    System.out.print((char) readlength);
                }  
            } while (readlength != -1);
        }
        catch(IOException error)
        {
            System.out.println("Error reading file.");
            return;
        }
        
        System.out.println();
        System.out.println();
     
       //Read file line by line into a String.
       try
        {
            inputtostring = new Scanner(new File("D:\\Application Data\\Java\\Javatxtfiles\\AdventofCode2016\\AdventofCodeDay8Part1.txt")).useDelimiter("\\Z").next();
           
            //Show String with input from file.
            System.out.println("Here is the saturated String object:");
            System.out.println();
            System.out.println(inputtostring);  
            
        }
        catch(IOException error)
        {
            System.out.println("Error scanning file into string.");
            return;
        }
         
        //Close the file.
        try
        {
            inputfile.close();
            
        }
        catch(IOException error)
        {
            System.out.println("Error closing file");
        }
       
        System.out.println();
        System.out.println();
        
        System.out.println("Grid solver activated: ");
        
        Grid inputgrid = new Grid();
        
        inputgrid.ShowGrid();
        
        System.out.println();
        
        //Tokenize input to substrings separated by //Z. (Each line)
        String[] tokens = inputtostring.split(System.getProperty("line.separator"));
        
        //Show tokenized String object.
        System.out.println("Here is the tokenized String object: ");
        System.out.println();
        
        for(int i = 0 ; i < tokens.length ; i++)
        {
            System.out.println(tokens[i]);
        }
        
        System.out.println();
        
        //Apply transformations to inputgrid.
        //Set specified String array input to be searched for.
        String rectset = "rect";
        String rotateset = "rotate";
        
        //String splitter tests.
        //Rect test.
        String rectstring = String.join("" , tokens[0]);
        System.out.println("Here is the rect string test");
        System.out.println(rectstring);
        String[] rectafterstringsplit = rectstringsplitter(rectstring);
        
         for(int i = 0 ; i < rectafterstringsplit.length ; i++)
        {
            System.out.println(rectafterstringsplit[i]);
        }
        
        System.out.println();
        System.out.println();
        
        //Rotate test.
        String rotatestring = String.join("", tokens[1]);
        System.out.println("Here is the rotate string test");
        System.out.println(rotatestring);
        String[] rotateafterstringsplit = rotatestringsplitter(rotatestring);
        
        for(int i = 0 ; i < rotateafterstringsplit.length ; i++)
        {
            System.out.println(rotateafterstringsplit[i]);
        }
        
        System.out.println();
        System.out.println();
        
        
        
        //If rect or rotate is found.
        for(int i = 0 ; i < tokens.length ; i++)
        {
            if(tokens[i].contains(rectset))
            {
                String rectstring1 = String.join("" , tokens[i]);
                String[] rectusestring = rectstringsplitter(rectstring1);
                System.out.println("Here is iteration " + (i + 1) + ":");
                
                for(int j = 1 ; j < rectusestring.length ; j++)
                {
                    System.out.println(rectusestring[j]);
                }
                
                System.out.println();
                
                //Type conversion from string to int.
                int rect1 = Integer.parseInt(rectusestring[1]);
                int rect2 = Integer.parseInt(rectusestring[2]);
                        
                //Call rect_call function.
                inputgrid.rect_call(inputgrid , rect1 , rect2);
                
                //Show updated grid after each iteration.
                inputgrid.ShowGrid();
                System.out.println();
            }
            
            else if(tokens[i].contains(rotateset))
            {
                String rotatestring1 = String.join("", tokens[i]);
                String[] rotateusestring = rotatestringsplitter(rotatestring1);
                System.out.println("Here is iteration " + (i + 1) + ":");
                
                for(int j = 1 ; j < rotateusestring.length ; j += 2)
                {
                    System.out.println(rotateusestring[j]);
                }
                
                System.out.println();
                
                //Type conversion from string to int.
                int rotate1 = Integer.parseInt(rotateusestring[3]);
                int rotate2 = Integer.parseInt(rotateusestring[5]);
                
                //Call rotate_call function.
                inputgrid.rotate_call(inputgrid , rotate1 , rotate2 , rotateusestring[1]);
                
                //Show updated grid after each iteration.
                inputgrid.ShowGrid();
                System.out.println();   
            }
            
        }
          
        int counterarray[] = new int[1];
        
        //Iterate through inputgrid and count for each occurance of subscript with element equal to 1.
        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 50 ; j++)
            {
                if(inputgrid.Grid[i][j] == 1)
                {
                    counterarray[0]++;
                }
            }
        }

        System.out.println(); 
        System.out.println("The number of grid pixels lit are " + counterarray[0]); 
       
        
        
        
        
        
        
    }
    
    
    public static String[] rectstringsplitter(String inputstring)
    {
       String[] splitstring = inputstring.split("\\D+");
       
       return splitstring;
    }
    
    public static String[] rotatestringsplitter(String inputstring)
    {
        String[] splitstring = inputstring.split("\\W");
        
        return splitstring;
    }
    
}

class Grid
{
    //Grid Definition
    int Grid[][] = new int [6][50];
    
    Grid()
    {
        //Create grid.
        System.out.println("Constucting empty Grid: ");
    }
     
    void ShowGrid()
    {
        //Show grid.
        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 50 ; j++)
            {
                System.out.print(Grid[i][j] + " ");
            }
            System.out.println();
        }
    } 
    
    //Function to turn on (1) specific array elements.
    void rect_call(Grid input , int first , int second)
    {
        for(int i = 0 ; i < 6 ; i++)
        {
            for(int j = 0 ; j < 50 ; j++)
            {
                if((j + 1) <= first)
                {
                    input.Grid[0][j] = 1;
                }
            }
        }
        for(int j = 0 ; j < 50 ; j++)
        {
            for(int i = 0 ; i < 6 ; i++)
            {
                if((i + 1) <= second & (j + 1) <= first)
                {
                    input.Grid[i][j] = 1;
                }
            }
        }
    }
    
    
    //Function to rotate specific array elements.
    void rotate_call(Grid input , int first , int second , String roworcolumn)
    {
        if(roworcolumn.contains("row"))
        {
            for(int i = 0 ; i < 6 ; i++)
            {
                if(i == first)
                {
                    int main[] = new int[50];
                    int maincounter = 0;
                    
                    //Copy second amount of elements into main array.
                    for(int k = (50 - second) ; k < 50  ; k++)
                    {
                        main[maincounter] = input.Grid[i][k];
                        maincounter++;
                    }
                        
                    //Copy rest of input array after second into main array.
                    for(int m = 0 ; m < (50 - second) ; m++)
                    {
                        main[maincounter] = input.Grid[i][m];
                        maincounter++;
                    }
                        
                    //Set input grid elements equal to main array elements
                    for(int n = 0 ; n < 50 ; n++)
                    {
                        input.Grid[i][n] = main[n];
                    }
                }
            }
        }
        
        else if(roworcolumn.contains("column"))
        {
             for(int j = 0 ; j < 50 ; j++)
            {
                if(j == first)
                {
                    int main[] = new int[6];
                    int maincounter = 0;
                        
                    //Copy second amount of elements into swapped array.
                    for(int k = (6 - second) ; k < 6 ; k ++)
                    {
                        main[maincounter] = input.Grid[k][j];
                        maincounter++;
                    }
                        
                    //Copy rest of input array after second into main array.
                    for(int m = 0 ; m < (6 - second) ; m ++)
                    {
                        main[maincounter] = input.Grid[m][j];
                        maincounter++;
                    }
                    
                    //Set input grid elements equal to main array elements
                    for(int n = 0 ; n < 6 ; n ++)
                    {
                        input.Grid[n][j] = main[n];
                    }
                }
            }
        }
    }
}
