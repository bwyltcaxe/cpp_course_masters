#include <iostream>
#include <unordered_map>

int evaluate_Collatz_seq_length (int num, std::unordered_map<int, int>& cache)
{
    int orig_num = num;
    int len = 1;

    while (num != 1) {
        /* Check that we already know the next Collatz sequence length.  */
        if (cache.find (num) != cache.end())
        {
            len += cache [num] - 1;
            break;
        }

        if (num % 2 == 0)
            num >>= 1;
        else
            num = 3 * num + 1;

        len++;
    }

    /* Save it for future evaluations.  */
    cache[orig_num] = len;

    return len;
}

void evaluate_longest_Collatz_seq (int limit)
{
    std::unordered_map<int, int> cache;
    int max_length = 0;
    int num_for_max_seq = 0;

    for (int num = 1; num <= limit; ++num)
    {
        int length = evaluate_Collatz_seq_length (num, cache);
        if (length > max_length)
        {
            max_length = length;
            num_for_max_seq = num;
        }
    }

    std::cout << "Number that gives the longest Collatz sequence: " << num_for_max_seq << std::endl;
    std::cout << "Collatz sequence length: " << max_length << std::endl;
}

int main ()
{
    const int limit = 10000;
    evaluate_longest_Collatz_seq (limit);
}

