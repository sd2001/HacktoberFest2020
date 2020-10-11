package library;

public class Livro {
	private String nameBook;
	private String nameAuthor;
	private int yearRelease;

	public Livro(String nameBook, String namString, int year) {
		this.nameBook = nameBook;
		this.nameAuthor = namString;
		this.yearRelease = year;
	}

	public String getNameBook() {
		return nameBook;
	}

	public void setNameBook(String nameBook) {
		this.nameBook = nameBook;
	}

	public String getNameAuthor() {
		return nameAuthor;
	}

	public void setNameAuthor(String nameAuthor) {
		this.nameAuthor = nameAuthor;
	}

	public int getYearRelease() {
		return yearRelease;
	}

	public void setYearRelease(int yearRelease) {
		this.yearRelease = yearRelease;
	}

}
