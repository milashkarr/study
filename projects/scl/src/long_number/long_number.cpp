#include "long_number.hpp"

using MAst::LongNumber;

LongNumber::LongNumber() : length(1), sign(POSITIVE) {
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	length = 0;
	delete [] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (this == &x) return true
        if (this->numbers == nullptr || x.numbers == nullptr) throw;
        if (this->sign == x.sign && this->length == x.length) {
            for (int i = 0; i < this->length; i++) {
                if (this->numbers[i] != x.numbers[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
}

bool LongNumber::operator != (const LongNumber& x) const {
	if (sign != x.sign) {
			return true;
		}
		else if (length != x.length) {
			return true;
		}
		else { 
			if (length >= x.length) {
				for (int i = 0; i < length; i++){
					if (numbers_[i] != x.numbers[i]) {
						return true;
					}
				}
			}
			else { 
				for (int i = 0; i < x.length; i++) {
					if (numbers_[i] != x.numbers[i]) {
						return true;
					} 
				}
			}
		}
		return false;
}

bool LongNumber::operator > (const LongNumber& x) {
		if (sign > x.sign) {
			return true;
		}
		else if (sign < x.sign) {
			return false;
		}

		if (length > x.length) {
			return (sign == POSITIVE);
		}
		else if (length < x.length) {
			return (sign == NEGATIVE);
		}

		for (int i = length - 1; i >= 0; i--) {
			if (numbers[i] > x.numbers[i]) {
				return (sign == POSITIVE);
			}
			else if (numbers[i] < x.numbers[i]) {
				return (sign == NEGATIVE);
			}
		}
		return false;
	}

bool LongNumber::operator < (const LongNumber& x) {
		if (sign < x.sign) {
			return true;
		}
		else if (sign > x.sign) {
			return false;
		}

		if (length < x.length) {
			return (sign == POSITIVE);
		}
		else if (length > x.length) {
			return (sign == NEGATIVE);
		}

		for (int i = length - 1; i >= 0; i--) {
			if (numbers[i] < x.numbers[i]) {
				return (sign == POSITIVE);
			}
			else if (numbers[i] > x.numbers[i]) {
				return (sign == NEGATIVE);
			}
		}
		return false;
	}

LongNumber LongNumber::operator+(const LongNumber& x) {
		int thisInt = this->toInt(*this);
		int otherInt = x.toInt(x);

		int sum = thisInt + otherInt;

		LongNumber result(sum);
		return result;
	}

	LongNumber LongNumber::operator-(const LongNumber& x) {
		int thisInt = this->toInt(*this);
		int otherInt = x.toInt(x);

		int sum = thisInt - otherInt;

		LongNumber result(sum);
		return result;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) {
		int thisInt = this->toInt(*this);
		int otherInt = x.toInt(x);

		int sum = thisInt * otherInt;

		LongNumber result(sum);
		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) {
		int thisInt = this->toInt(*this);
		int otherInt = x.toInt(x);

		int sum = thisInt / otherInt;

		LongNumber result(sum);
		return result;
	}

	LongNumber LongNumber::operator%(const LongNumber& x) {
		int thisInt = this->toInt(*this);
		int otherInt = x.toInt(x);

		int sum = thisInt % otherInt;

		LongNumber result(sum);
		return result;
	}

int LongNumber::get_digits_number() const {
	return length;
}

bool LongNumber::is_negative() const {
	return sign == NEGATIVE;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		int length = 0;
		for (int i = 0; str[i] != END; i++) {
			length++;
		}
		return length;
	}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace MAst {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == LongNumber::NEGATIVE) {
			os << LongNumber::MINUS;
		}
		for (int i = 0; i < x.length; i++) {
			os << x.numbers[x.length - i - 1];
		}
		return os;
	}
}
