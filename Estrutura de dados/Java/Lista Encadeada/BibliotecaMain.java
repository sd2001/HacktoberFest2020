package listaencadeada;

public class BibliotecaMain {

	public static void main(String[] args) {
		Library lib = new Library();

		lib.add_Book(new Book("Os Inovadores", "FJ", 1863));
		lib.add_Book(new Book("Os Miseraveis", "James", 1963));
		lib.add_Book(new Book("Percy Jackson", "Arthur", 2003));
		lib.add_Book(new Book("Harry potter", "JK", 2020));

		lib.showList();
		System.out.println("----------------------------------------------");
		lib.removeElement("Os Inovadores");
		// lib.removeElement("Harry potter");
		// lib.removeElement("Percy Jackson");
		lib.removeElement("Os Miseraveis");

		lib.showList();
		System.out.println("----------------------------------------------");
		System.out.println("Book's name: " + lib.search("Os Inovadores"));

	}

}
