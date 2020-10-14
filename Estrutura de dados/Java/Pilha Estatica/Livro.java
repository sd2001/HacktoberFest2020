package biblioteca;

public class Livro {

	private String nameBook;
	private String authorBook;
	private int yearBook;

	public Livro(String nome, String autor, int ano) {
		nameBook = nome;
		authorBook = autor;
		ano = yearBook;
	}

	public String getNameBook() {
		return nameBook;
	}

	public void setNameBook(String nameBook) {
		this.nameBook = nameBook;
	}

	public String getAuthorBook() {
		return authorBook;
	}

	public void setAuthorBook(String authorBook) {
		this.authorBook = authorBook;
	}

	public int getYearBook() {
		return yearBook;
	}

	public void setYearBook(int yearBook) {
		this.yearBook = yearBook;
	}

}
