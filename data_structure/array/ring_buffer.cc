#include <array>
#include <algorithm>

template <typename size_t, typename RingSize>
class Histogram
{
    std::array<size_t, RingSize> m_ringBuffer;
    size_t m_total;
    size_t m_position;

    public:
        Histogram() :m_total(0) {
            std::fill_n(m_ringBuffer.begin(), RingSize, 0);
        }

        void addHit() {
            m_ringBuffer[m_position] += 1;
            m_total += 1;
        }

        void incrementPosition() {
            if (++m_position >= RingSize) {
                m_position = 0;
            }

            m_total -= m_ringBuffer[m_position];
            m_ring_buffer[m_position] = 0;
        }

        double runningAverage() const {
            return (double)m_total / (double)RingSize;
        }
};

int main()
{
    return 0;
}
