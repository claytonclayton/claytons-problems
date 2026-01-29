
#include <iostream>
#include <cmath>

using namespace std;

int a, b, c; 

// quadratic formula (in case ur a dummy)
// x = (-b +/- sqrt(b^2 - 4ac)) / 2a

void simplify_fraction(int& num, int& den) {
    if (den < 0) {
	num *= -1;
	den *= -1;
    }
    // very slow teehee
    for (int div = 2; div <= den; div++) {
	while (num % div == 0 && den % div == 0) {
	    num /= div;
	    den /= div;
	}		
    }
}

string frac_string(int num, int den) {
    if (num == 0) return "0";
    if (den == 1) return to_string(num); 
    return to_string(num) + "/" + to_string(den);
}        

bool is_square(int num) {
    return pow(sqrt(num), 2) == num;
}

int main() {
    // quadratic formula
    // (minb +/- sqrt(discrim)) / den
    cin >> a >> b >> c;
    int discrim = pow(b, 2) - 4 * a * c;   
    int den     = 2 * a;
    int minb    = -b;

    // rewrite as
    // minb/den +/- sqrt(discrim/den^2)
    // then simplify each fraction
    int denl = den;
    int denr = pow(den, 2);
    simplify_fraction(minb, denl);
    simplify_fraction(discrim, denr);

    // if both discrim and denr are square numbers
    // then we can get the square of both
    // and omit the sqrt root sign in
    // the final output
    bool use_sqrt = !(is_square(discrim) && is_square(denr));
    if (!use_sqrt) {
	discrim = sqrt(discrim);
	denr = sqrt(denr);
    }

    // get string representation of each
    // side of the +/- sign
    string fracl = frac_string(minb, denl);
    string fracr = frac_string(discrim, denr);

    // if discrim < 0 then there are no real solutions
    if (discrim < 0) {
	cout << "none" << endl;
	return 0;
    }
    // if discrim == 0 then instead of adding +/- 0
    // we just omit fraction
    if (minb != 0) cout << fracl << " ";
    if (discrim > 0) {
	cout << "+/- ";
	if (use_sqrt) cout << "sqrt(";
	cout << fracr;
	if (use_sqrt) cout << ")";

    }
    cout << endl;
}
