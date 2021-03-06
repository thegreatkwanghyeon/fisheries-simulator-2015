#ifndef __WELL512_H__
#define __WELL512_H__

class Well512{
	private : 

		unsigned int state[16];
		unsigned int index;

	public : 

		Well512(){
			index = 0;
			for (unsigned int i = 0; i < 16; i++){
				state[i] = i;
			}
		}

		~Well512(){
			
		}

		unsigned int Next(int minValue, int maxValue){
			if(minValue == maxValue)
				return maxValue;
			else
				return (unsigned int)((Next() % (maxValue - minValue)) + minValue);
		}

		unsigned int Next(unsigned int maxValue){
			return Next() % maxValue;
		}

		unsigned int Next(){
			unsigned int a, b, c, d;

			a = state[index];
			c = state[(index + 13) & 15];
			b = a ^ c ^ (a << 16) ^ (c << 15);
			c = state[(index + 9) & 15];
			c ^= (c >> 11);
			a = state[index] = b ^ c;
			d = a ^ ((a << 5) & 0xda442d24U);
			index = (index + 15) & 15;
			a = state[index];
			state[index] = a ^ b ^ d ^ (a << 2) ^ (b << 18) ^ (c << 28);

			return state[index];
		}

		float NextFloat(){
			unsigned int nRandValue = Next();
			union {unsigned long ul; float f;} p;
			p.ul = (((nRandValue *= 16807)&0x007fffff)-1)|0x3f800000;
			return p.f-1.f;
		}

		float NextFloat(float minValue, float maxValue){
			return minValue + NextFloat() * (maxValue - minValue);
		}

		float NextFloat(float maxValue){
			return NextFloat()*maxValue;
		}
};

#endif