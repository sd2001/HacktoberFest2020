package listaencadeada;

public class Book {
	private String name;
	private String author;
	private int year;
	private Book proximo;

	public Book(String name, String author, int year) {
		proximo = null;
		this.name = name;
		this.author = author;
		this.year = year;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getAuthor() {
		return author;
	}

	public void setAuthor(String author) {
		this.author = author;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public Book getProximo() {
		return proximo;
	}

	public void setProximo(Book proximo) {
		this.proximo = proximo;
	}

}
