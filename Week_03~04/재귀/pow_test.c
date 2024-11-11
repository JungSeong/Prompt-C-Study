#include <gmp.h>

int main() {
    mpz_t result; // mpz_t는 GMP에서 제공하는 큰 정수 타입
    mpz_init(result);

    // result = 2^100
    mpz_ui_pow_ui(result, 2, 100);
    mpz_sub_ui(result, result, 1); // result = 2^100 - 1

    gmp_printf("%Zd\n", result); // 큰 수를 출력

    mpz_clear(result);
    return 0;
}