/* Generates a series of Insert Statements from an existing file for batch insertion
of an SQL database. */

import java.io.*;
import java.util.Scanner;

public class GenerateSQL
{
	public static void main(String[] args) throws IOException
	{
		Scanner file = new Scanner(new File("C:/xampp/www/Bingo/stmt.txt"));
		
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:/xampp/www/Bingo/out.txt", true));
		
		String insert = "INSERT INTO items(content) VALUES(\"";
		String insertend = "\");";
		while(file.hasNextLine())
		{
			String result = insert + file.nextLine() + insertend;
			writer.write(result);
			writer.newLine();
			writer.flush();
			
			
		}
		writer.close();
	}
	
	
	
}