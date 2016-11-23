/*(∗2) Type in the calculator example and get it to work. Do not ‘‘save time’’
by using an already entered text. You’ll learn most from finding and correcting
‘‘little silly errors.’’*/
#include <map>
#include <iostream>
#include <string>

enum class Kind : char {
  name, number, end,
  plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
};

struct Token
{
  Kind kind;
  std::string string_value;
  double number_value;
};

std::map<std::string,double> table;
double expr(bool);

int no_of_errors;
double error(const std::string& s)
{
  no_of_errors++;
  std::cerr << "error: " << s << '\n';
  return 1;
}

class Token_stream {
  public:
    Token_stream(std::istream& s) : ip{&s}, owns{false} { }
    Token_stream(std::istream* p) : ip{p}, owns{true} { }
    Token_stream() { close(); }
    Token get();
    Token& current();
    // read and return next token
    // most recently read token
    void set_input(std::istream& s) { close(); ip = &s; owns=false; }
    void set_input(std::istream* p) { close(); ip = p; owns = true; }

  private:
    void close() { if (owns) delete ip; };
    std::istream* ip;
    bool owns;
    Token ct {Kind::end};
    // pointer to an input stream
    // does the Token_stream own the istream?
    // current token
};

Token& Token_stream::current()
{
  return ct;
}

Token Token_stream::get()
{
  char ch = 0;
  do { // skip whitespace except ’\n’
    if (!ip->get(ch)) return ct={Kind::end};
  } while (ch!='\n' && isspace(ch));

  switch (ch) {
    case 0:
      return ct={Kind::end};
      // assign and return
    case ';':
    case '\n':
      return ct={Kind::print};
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
      return ct={static_cast<Kind>(ch)};
    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
    case '.':
      ip->putback(ch);
      // put the first digit (or .) back into the input stream
      *ip >> ct.number_value;
    // read number into ct
      ct.kind=Kind::number;
      return ct;
    default:
        // NAME, NAME=, or error
        if (isalpha(ch)) {
          ct.string_value = ch;
          while (ip->get(ch) && isalnum(ch))
            ct.string_value += ch; // append ch to end of string_value
          ip->putback(ch);
          ct.kind=Kind::name;
          return ct;
        }

      error("bad token");
      return ct={Kind::print};
  }
}

Token_stream ts {std::cin};

double prim(bool get)
// handle primar ies
{
  if (get) ts.get(); // read next token
  switch (ts.current().kind) {
    case Kind::number:
      // floating-point constant
      {
        double v = ts.current().number_value;
        ts.get();
        return v;
      }
    case Kind::name:
      {
        double& v = table[ts.current().string_value];
        if (ts.get().kind == Kind::assign) v = expr(true);
        return v;
      }

    // find the corresponding
    // ’=’ seen: assignment246
    case Kind::minus:
      // unar y minus
      return -prim(true);
    case Kind::lp:
      {
        auto e = expr(true);
        if (ts.current().kind != Kind::rp) return error("')' expected");
        ts.get();
        // eat ’)’
        return e;
      }
    default:
      return error("primar y expected");
  }
}

double term(bool get)
{
  double left = prim(get);
  // multiply and divide
  for (;;) {
    switch (ts.current().kind) {
    case Kind::mul:
      left *= prim(true);
      break;
    case Kind::div:
      if (auto d = prim(true)) {
        left /= d;
        break;
      }
      return error("divide by 0");
    default:
      return left;
    }
  }
}

double expr(bool get)
{
  double left = term(get);
  // add and subtract
  for (;;)
  {
    // ‘‘forever’’
    switch (ts.current().kind)
    {
      case Kind::plus:
        left += term(true);
        break;
      case Kind::minus:
        left -= term(true);
        break;
      default:
        return left;
    }
  }
}



// use input from cin
void calculate()
{
  for (;;) {
    ts.get();
    if (ts.current().kind == Kind::end) break;
    if (ts.current().kind == Kind::print) continue;
    std::cout << expr(false) << '\n';
  }
}
int main()
{
table["pi"] = 3.1415926535897932385;
table["e"] = 2.7182818284590452354;
// inser t predefined names
calculate();
return no_of_errors;
}
