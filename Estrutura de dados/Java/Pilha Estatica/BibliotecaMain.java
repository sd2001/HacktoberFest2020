package biblioteca;

import java.util.Scanner;

public class BibliotecaMain {

	public static void main(String[] args) {
		LibraryStack ls = new LibraryStack(10);

		ls.push(new Livro("Os Inovadores", "FJ", 1998));
		ls.push(new Livro("Lenda do cavaleiro sem cabeça", "FJJ", 1997));
		ls.push(new Livro("Percy Jackson", "JA", 1998));
		ls.push(new Livro("Holmes", "Artur", 1997));

		Livro l = ls.topoStack();
		System.out.println("Nome: " + l.getNameBook());

		// ls.showStack();
		ls.pop();
		ls.pop();

		Livro l1 = ls.topoStack();
		System.out.println("Nome: " + l1.getNameBook());

	}

}
