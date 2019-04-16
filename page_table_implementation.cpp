#include "iostream"
#include "numeric"
#include "algorithm"
#include "cmath"
//#include "experimental/random"
#include "vector"
#include "random"
using namespace std;
using ull = unsigned long long;

/*
 * Program Size = 5*1024*1024 bytes (Bits required to store this size = 23 bits)
 * Page Size = 2*1024 bytes
 * Page Offset = 11 bits (because 2^11 = Page Size)
 *
 * During translation page offset is not changed.
 *
 * Here we assume that we have 18-bit machine i.e. only 18 bits are addressable
 * So, largest possible program that can run without the need of virtual memory
 * is 2^18 = 256KB
 *
 * But we want to run 5MB program here so we need virtual memory
 * and translation from virtual memory to physical memory is done using Page table.
 *
 * Here we use 23-bit long virtual address.
 * So, largest possible program that can run using virtual memory is 2^23 = 8MB
 *
 * Size of page table = 23-(page offset) = 23-11 = 12 bits
 */


// returns the offset of virtual address 'a' where is 'k' is the number of mask bits
long offset(long a, long k)
{
    string mask(k, '1');
    long mask_int = stol(mask, nullptr, 2);
    return a&mask_int;
}

// returns the numebers of bits required for offset for the page size
// for page size of 'k' we need log2(k) bits to store [0, k-1]
long offset_bits(long page_size)
{
    return log2(page_size);
}

long bits_required(long k)
{
    return floor(log2(k))+1;
}

ull operator"" _MB(ull k){ return k*1024*1024; }
ull operator"" _KB(ull k){ return k*1024; }

struct virtual_memory_error: public exception
{
    virtual_memory_error() {}
    virtual_memory_error(string msg): msg(msg) {}
    const char * what() const throw()
    {
        return msg.c_str();
    }
private:
    string msg;
};


// entries marked with -1 indicates that the page is on disk
vector<long> init_page_table(ull program_size, long virtual_address_bits, long physical_address_bits, ull page_size)
{
    if(bits_required(program_size) > virtual_address_bits)
        throw virtual_memory_error("Not enough memory ran out of virtual memory");
    if(offset_bits(page_size) > physical_address_bits)
        throw virtual_memory_error("Page size too large to fit");

    long no_offset_bits = offset_bits(page_size);
    vector<long> page_table(1<<(bits_required(program_size)-no_offset_bits), -1);
    vector<bool> memory_pool(1<<(physical_address_bits-no_offset_bits), false);


    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<long> dis(0, memory_pool.size()-1);

    //for each entry in page_table
    for(auto& e: page_table)
    {
        if(all_of(memory_pool.begin(), memory_pool.end(), [](bool v){ return v; })) break;

        long random_idx = dis(gen);
        while(memory_pool[random_idx] == true) {
            random_idx = dis(gen);
        }
        e = random_idx;
        memory_pool[random_idx] = true;
    }
//    cout << "Page table initialised" << '\n';
    return page_table;
}

// translate virtual address va, by looking into the page table and page size
string translate_va(long va, const vector<long>& page_table, long page_size)
{
    long lower_offset = offset(va, offset_bits(page_size));
    long virtual_page_number = va>>offset_bits(page_size);
    cout << "Lower offset: " << lower_offset << '\n';
    cout << "VPN: " << virtual_page_number << '\n';

    return to_string(page_table[virtual_page_number])+"|"+to_string(lower_offset);
}

int main()
{
    long virtual_address_bits = 23, addressable_bits = 18, page_size = 2_KB, program_size = 5_MB;
    vector<long> pt = init_page_table(program_size, virtual_address_bits, addressable_bits, page_size);
//    cout << "In main\n";
    cout << translate_va((1<<18)+(1<<10), pt, page_size) << '\n';
    return 0;
}