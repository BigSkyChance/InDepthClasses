#ifndef CLASS_H
#define CLASS_H

using namespace std;

class String
	{
	public:
					String		();
					String		(const String & Str); 
		explicit	String		(const char []);
					~String		();
		void		Copy		(const String &);
		void		Copy		(const char[]);
		void		Concat		(const String &);
		void		Concat		(const char[]);
		int			Compare		(const char []) const;
		int			Compare		(const String &) const;
		void		DisplayLine	() const;
		void		Display(ostream & out = cout) const;
		istream &	Read(istream & = cin);
		int			Len();
		String &	operator = (const String &);
		String &	operator = (const char[]);
		bool		operator ==	(const String &) const;
		bool		operator <	(const String &) const;
		bool		operator <= (const String &) const;
		bool		operator != (const String &) const;
		bool		operator >= (const String &) const;
		bool		operator >	(const String &) const;
		bool		operator == (const char[]) const;
		bool		operator <	(const char[]) const;
		bool		operator <= (const char[]) const;
		bool		operator != (const char[]) const;
		bool		operator >= (const char[]) const;
		bool		operator >  (const char[]) const; // end of comparison operators
		String &	operator += (const String &);
		String &	operator += (const char[]);
		String	 	operator +	(const String &);
		String		operator +	(const char[]) const;

		

	private:
		size_t		NumChars;
		size_t		NumSlots;
		char *		pChar;
		char *		pTemp = "";

		
	};

inline void String::DisplayLine() const
{
	cout << pChar << endl;
}

inline void String::Display(ostream & out) const
{
	{
		cout << pChar;
	}
}

inline ostream & operator << (ostream & out, const String & Str)
{
	Str.Display(out);
	return out;
}

inline istream & operator >> (istream & in, String & Str)
{
	return Str.Read(in);
}
#endif