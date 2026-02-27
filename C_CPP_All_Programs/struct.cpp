#include <iostream>
using namespace std;

/*
Guidelines: when to use `struct` vs `class`

- Use `struct` when:
  - You have a simple passive data aggregate (plain-old-data or POD-like).
  - Members are intended to be public by default.
  - The type primarily groups related public data with minimal behavior.
  - You want concise syntax and no need for strict encapsulation.

- Use `class` when:
  - You need encapsulation (private/protected members).
  - You want to expose a controlled interface via public member functions.
  - Invariants must be enforced or state must be hidden.
  - You need inheritance with controlled access specifiers or virtual behavior.

Example guidance for this file:
- `Rectangle` is a simple data holder with a small helper `display()`.
  It's appropriate to use `struct` because its members are public and it's a lightweight aggregate.
- If you later need to enforce invariants (e.g., non-negative dimensions) or hide fields,
  convert to `class`, make `width`/`height` private, and provide accessors/mutators that validate values.
*/

struct Rectangle
{
	int width;   // public data: simple, intended for direct access -> suitable for `struct`
	int height;  // public data
	void display()
	{
		cout << "Width =" << width << " Height =" << height << endl;
	}
};

int main()
{
	Rectangle a;
	a.width = 10;
	a.height = 20;
	a.display();

	return 0;
}