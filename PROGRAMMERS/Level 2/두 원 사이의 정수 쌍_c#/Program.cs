using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codingTest
{
    public class Solution
    {
        public long solution(int r1, int r2)
        {
            long answer = 0;
            long minRadiusSq = (long)r1 * (long)r1;
            long maxRadiusSq = (long)r2 * (long)r2;

            //y가 주어질 때 x의 개수를 새면된다
            for (int y = 0; y < r2; ++y)
            {
                long ySq = (long)y * (long)y;
                long minX = (long)Math.Ceiling( Math.Sqrt((minRadiusSq > ySq) ? (minRadiusSq - ySq) : 0) );
                long maxX = (long)Math.Floor( Math.Sqrt(maxRadiusSq - ySq));

                answer += maxX - ((minX != 0) ? minX - 1 : 0);
            }

            return answer * 4;
        }
    }

    public class Test
    {
        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.solution(2, 3));
        }
    }
}