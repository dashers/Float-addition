/*	This function will take 2 inputs and calculate the sum of the inputs.
	  The result of the addition will be returned to the calling function.
    
    Debajyoti Dash
*/

#include <stdio.h>
#define DO_DEBUGGING_PRINTS 0

int FloatAdd(int op1, int op2)
{

	unsigned int s1, e1, m1;
	int ispositivezero1 =0 , isnegativezero1 =0,
		ispositivezero2 =0 , isnegativezero2 =0,
		ispositiveinfinity1 =0, isnegativeinfinity1 =0,
		ispositiveinfinity2 =0, isnegativeinfinity2 =0,
		isNormalized1 = 0, isNormalized2 = 0,
		isDeNormalized1 = 0, isDeNormalized2 = 0,
		isNaN1 =0, isNaN2 =0;

	s1 = op1 >> 31;
	e1 = op1 & 0x7f800000;
	e1 >>= 23;
	m1 = op1 & 0x007fffff;

#if DO_DEBUGGING_PRINTS
	fprintf(stderr, "First Input: 0x%08x\n", op1);
	fprintf(stderr, "sign (hex): %08x", s1);
	fprintf(stderr, "   exponent (hex): %08x", e1);
#endif

	if(e1 == 0x00 && m1 != 0x00000000) {
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is in denormalized form\n\n", op1);
#endif
		isDeNormalized1 = 1;
	}
	else if (e1 == 0xff && m1 != 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is NaN\n\n", op1);
#endif
		isNaN1 = 1;
	}
	else if (s1 == 0 && e1 == 0xff && m1 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is Positive Infinity\n\n", op1);
#endif
		ispositiveinfinity1 = 1;
	}
	else if (s1 == 0xffffffff && e1 == 0xff && m1 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is Negative Infinity\n\n", op1);
#endif
		isnegativeinfinity1 = 1;
	}
	else if (s1 == 0 && e1 == 0x00 && m1 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is Positive Zero\n\n", op1);
#endif
		ispositivezero1 = 1;
	}
	else if (s1 == 0xffffffff && e1 == 0x00 && m1 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is Negative Zero\n\n", op1);
#endif
		isnegativezero1 = 1;
	}
	else if (e1 != 0x00 && e1 != 0xff){
		m1 += 0x800000;
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m1);
		fprintf(stderr, "First Input:0x%08x  is Normalized\n\n", op1);
#endif
		isNormalized1 =1;
	}



	unsigned int s2, e2, m2;

	s2 = op2 >> 31;
	e2 = op2 & 0x7f800000;
	e2 >>= 23;
	m2 = op2 & 0x007fffff;

#if DO_DEBUGGING_PRINTS
	fprintf(stderr, "Second Input: 0x%08x\n", op2);
	fprintf(stderr, "sign (hex): %08x", s2);
	fprintf(stderr, "   exponent (hex): %08x", e2);
#endif	

	if(e2 == 0x00 && m2 != 0x00000000) {
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is in denormalized form\n\n", op2);
#endif
		isDeNormalized2 = 1;
	}
	else if (e2 == 0xff && m2 != 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is NaN\n\n", op2);
#endif
		isNaN2 = 1;
	}
	else if (s2 == 0 && e2 == 0xff && m2 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is Positive Infinity\n\n", op2);
#endif
		ispositiveinfinity2 = 1;
	}
	else if (s2 == 0xffffffff && e2 == 0xff && m2 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is Negative Infinity\n\n", op2);
#endif
		isnegativeinfinity2 = 1;
	}
	else if (s2 == 0 && e2 == 0x00 && m2 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is Positive Zero\n\n", op2);
#endif
		ispositivezero2 = 1;
	}
	else if (s2 == 0xffffffff && e2 == 0x00 && m2 == 0x00000000){
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is Negative Zero\n\n", op2);
#endif
		isnegativezero2 = 1;
	}
	else if (e2 != 0x00 && e2 != 0xff){
		m2 += 0x800000;
#if DO_DEBUGGING_PRINTS
		fprintf(stderr, "   significand (hex): %08x\n", m2);
		fprintf(stderr, "Second Input:0x%08x  is Normalized\n\n", op2);
#endif
		isNormalized2 =1;
	}



	/* Handle NaN input */
	if (isNaN1 == 1 && isNaN2 == 1){
		if((op2 >> 23) == 0x000000FF){
			op2 |= 0x00400000;
			return op2;
		} 
		else if ((op1 >> 23) == 0x000000FF) {
			op1 |= 0x00400000;
			return op1;
		}
		else {
			op2 &= 0x7FFFFFFF;
			op2 |= 0x00400000;
			return op2;
		}
	}
	else if(isNaN1 == 1){
		op1 |= 0x00400000;
		return op1;
	}else if(isNaN2 == 1){
		op2 |= 0x00400000;
		return op2;
	}

	/* Handle zero input */

	if(	(ispositivezero1 == 1 || isnegativezero1 == 1) && 
		(ispositivezero2 == 1 || isnegativezero2 == 1)	) {
		return 0;
	}else if(ispositivezero1 == 1 || isnegativezero1 == 1){
		return op2;
	}else if(ispositivezero2 == 1 || isnegativezero2 == 1){
		return op1;
	}


	/* Handle Infinity input */

	if(	(ispositiveinfinity1 == 1 || isnegativeinfinity1 == 1) && 
		(ispositiveinfinity2 == 1 || isnegativeinfinity2 == 1) ) {
		return op1;
	}else if(ispositiveinfinity1 == 1 || isnegativeinfinity1 == 1){
		return op1;
	}else if(ispositiveinfinity2 == 1 || isnegativeinfinity2 == 1){
		return op2;
	}


	/* Compute addition if both numbers have same sign */

	if((s1 == 0 && s2 == 0) || (s1 == 0xffffffff && s2 == 0xffffffff)) {
#if DO_DEBUGGING_PRINTS	
		fprintf(stderr, "Both inputs are of same sign\n");
#endif
		int diff, s, e, m, result;
		int moveguard, movesticky, temp_m, guardbit, stickybit,
			overflow = 0 , overflow_m;

		/* This if logic will add numbers of same signs if exponent of op1 is greater
			than exponent of op2 */
		
		if(e1>e2){
#if DO_DEBUGGING_PRINTS
			fprintf(stderr, "Exponent of op1 > Exponent of op2\n");
#endif
			s = s1;
			e = e1;
			
			if(isNormalized1 == 1 && isNormalized2 == 1)	diff = e1-e2;
			else diff = e1-e2-1;
			
			if(diff > 31) return op1;

			temp_m = m2;

			if(diff > 1){
				moveguard = diff - 2;
				if(moveguard != 0) {
					movesticky = 32-moveguard;
					if(((temp_m << movesticky) & 0xffffffff) == 0) stickybit = 0;
					else stickybit = 1;
				}else stickybit = 0;
				guardbit = ((temp_m >> moveguard) & 0x00000003);
			}
			else{
				stickybit = 0;
				if (diff == 1){
					if((temp_m & 0x00000001) == 0) guardbit = 0;
					else guardbit = 0x00000002;
				}else guardbit = 0;
			}

			m1 = (m1 << 3) + 0x00000000;
			m2 = m2 >> diff;
			m2 = (m2 << 3) + (guardbit << 1) + stickybit;
			m = m1 + m2;

			overflow_m = m;
			stickybit = (m & 0x00000001);
			if(((m>>3)>>24) == 0x00000001) m >>= 1, e = e + 1, overflow = 1;

			guardbit = ((m >> 1) & 0x00000003);
			if(stickybit != 1) stickybit = (m & 0x00000001);
			m >>= 3;

			if(guardbit == 0x00000003) m++;
			else if ((guardbit == 0x00000002) && stickybit == 1) m++;
			else if ((guardbit == 0x00000002) && stickybit == 0){
				if ((m & 0x00000001) == 0x00000001) m++;
			}
			else if((guardbit == 0x00000000) || (guardbit == 0x00000001)){
				// Truncate
			}


			if(isDeNormalized1 == 1 && isDeNormalized2 == 1)
				m = m & 0x00ffffff;
			else
				m = m & 0x007fffff;

			if (e == 0x000000ff) {
				m = 0x00000000;
				result = ((s << 31) | (e << 23)) + m;
				return result;
			}

			result = ((s << 31) | (e << 23)) + m;

#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;
		}

		/* This if logic will add numbers of same signs if exponent of op2 is greater
			than exponent of op1 */

		else if(e2>e1) {
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Exponent of op2 > Exponent of op1\n");
#endif
			s = s2;
			e = e2;
			
			if(isNormalized1 == 1 && isNormalized2 == 1)	diff = e2-e1;
			else diff = e2-e1-1;

			if(diff > 31) return op2;

			temp_m = m1;

			if(diff > 1){
				moveguard = diff - 2;
				if(moveguard != 0) {
					movesticky = 32-moveguard;
					if(((temp_m << movesticky) & 0xffffffff) == 0) stickybit = 0;
					else stickybit = 1;
				}else stickybit = 0;
				guardbit = ((temp_m >> moveguard) & 0x00000003);
			}
			else{
				stickybit = 0;
				if (diff == 1){
					if((temp_m & 0x00000001) == 0) guardbit = 0;
					else guardbit = 0x00000002;
				}else guardbit = 0;
			}
			
			m2 = (m2 << 3) + 0x00000000;
			m1 = m1 >> diff;
			m1 = (m1 << 3) + (guardbit << 1) + stickybit;
			m = m1 + m2;

			overflow_m = m;
			stickybit = (m & 0x00000001);
			if(((m>>3)>>24) == 0x00000001) m >>= 1, e = e + 1, overflow = 1;

			guardbit = ((m >> 1) & 0x00000003);
			if(stickybit != 1) stickybit = (m & 0x00000001);
			m >>= 3;

			if(guardbit == 0x00000003) m++;
			else if ((guardbit == 0x00000002) && stickybit == 1) m++;
			else if ((guardbit == 0x00000002) && stickybit == 0){
				if ((m & 0x00000001) == 0x00000001) m++;
			}
			else if((guardbit == 0x00000000) || (guardbit == 0x00000001)){
				// Truncate
			}

			
			if(isDeNormalized1 == 1 && isDeNormalized2 == 1)
				m = m & 0x00ffffff;
			else
				m = m & 0x007fffff;

			if (e == 0x000000ff) {
				m = 0x00000000;
				result = ((s << 31) | (e << 23)) + m;
				return result;
			}
			
			result = ((s << 31) | (e << 23)) + m;

#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;
		}

		/* This else logic will add numbers of same signs if exponents are same 
			for both numbers */

		else{
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Same exponent of both Operands\n");
#endif
			s = s2;
			e = e2;

			stickybit = 0;
			guardbit = 0;

			m = m1 + m2;

			overflow_m = m;
			
			if((m>>24) == 0x00000001) m >>= 1, e = e + 1, overflow = 1;

			if(overflow == 1)
				guardbit = ((overflow_m << 1) & 0x00000003);
				//guardbit = ((((overflow_m << 2) + guardbit) >> 1) & 0x00000003);

			if(guardbit == 0x00000003) m++;
			else if ((guardbit == 0x00000002) && stickybit == 1) m++;
			else if ((guardbit == 0x00000002) && stickybit == 0){
				if ((m & 0x00000001) == 0x00000001) m++;
			}
			else if((guardbit == 0x00000000) || (guardbit == 0x00000001)){
				// Truncate
			}

			if(isDeNormalized1 == 1 && isDeNormalized2 == 1)
				m = m & 0x00ffffff;
			else
				m = m & 0x007fffff;

			if (e == 0x000000ff) {
				m = 0x00000000;
				result = ((s << 31) | (e << 23)) + m;
				return result;
			}
			
			result = ((s << 31) | (e << 23)) + m;

#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;
		}

	}

	/* Compute addition if both numbers have opposite sign */

	else{
#if DO_DEBUGGING_PRINTS	
		fprintf(stderr, "One input is Negative\n");
#endif
		int diff, s, e, m, result;
		int moveguard, movesticky, temp_m,
			guardbit, stickybit, overflow = 0, overflow_m;

		/* This if logic will add numbers of opposite signs if exponent of op1 is greater
			than exponent of op2 */

		if(e1>e2){
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Exponent of op1 > Exponent of op2\n");
#endif
			s = s1;
			e = e1;

			if(isNormalized1 == 1 && isNormalized2 == 1)	diff = e1-e2;
			else diff = e1-e2-1;

			if(diff > 31) return op1;

			temp_m = m2;

			if(diff > 1){
				moveguard = diff - 2;
				if(moveguard != 0) {
					movesticky = 32-moveguard;
					if(((temp_m << movesticky) & 0xffffffff) == 0) stickybit = 0;
					else stickybit = 1;
				}else stickybit = 0;
				guardbit = ((temp_m >> moveguard) & 0x00000003);
			}
			else{
				stickybit = 0;
				if (diff == 1){
					if((temp_m & 0x00000001) == 0) guardbit = 0;
					else guardbit = 0x00000002;
				}else guardbit = 0;
			}

			m1 = (m1 << 3) + 0x00000000;
			m2 = m2 >> diff;
			m2 = (m2 << 3) + (guardbit << 1) + stickybit;
			m = m1 - m2;

			overflow_m = m;

			if(((m>>3)>>24) == 0x00000001) m >>= 1, e = e + 1, overflow = 1;

			if(overflow == 1)
				guardbit = ((((overflow_m << 2) + guardbit) >> 1) & 0x00000003);

			unsigned int m_temp, e_temp, count=0;
			m_temp = m >> 3;
			e_temp = m_temp & 0x7f800000;
			e_temp >>= 23;

			while (e_temp == 0x00 || e_temp == 0xff){
				m = m << 1;
				m_temp = m_temp << 1;
				if (m == 0) return 0;
				count++;
				e_temp = m_temp & 0x7f800000;
				e_temp >>= 23;			
			}

			guardbit = ((m >> 1) & 0x00000003);
			stickybit = (m & 0x00000001);

			m >>= 3;

			if(guardbit == 0x00000003) m++;
			else if ((guardbit == 0x00000002) && stickybit == 1) m++;
			else if ((guardbit == 0x00000002) && stickybit == 0){
				if ((m & 0x00000001) == 0x00000001) m++;
			}
			else if((guardbit == 0x00000000) || (guardbit == 0x00000001)){
				// Truncate
			}

			m = m & 0x007fffff;

			if(count > 0){
				if(count >= e1){
					e = 0;
					//m = temp_m1 - (temp_m2 >> diff);
					m = (overflow_m << (e1-1)) >> 3;
				}
				else e = e1 - count;
			}				

			if (e == 0x000000ff) {
				m = 0x00000000;
				result = ((s << 31) | (e << 23)) + m;
				return result;
			}

			result = ((s << 31) | (e << 23)) + m;

#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;
		}

		/* This if logic will add numbers of opposite signs if exponent of op2 is greater
			than exponent of op1 */

		else if(e2>e1){
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Exponent of op2 > Exponent of op1\n");
#endif
			s = s2;
			e = e2;

			if(isNormalized1 == 1 && isNormalized2 == 1)	diff = e2-e1;
			else diff = e2-e1-1;

			if(diff > 31) return op2;

			temp_m = m1;

			if(diff > 1){
				moveguard = diff - 2;
				if(moveguard != 0) {
					movesticky = 32-moveguard;
					if(((temp_m << movesticky) & 0xffffffff) == 0) stickybit = 0;
					else stickybit = 1;
				}else stickybit = 0;
				guardbit = ((temp_m >> moveguard) & 0x00000003);
			}
			else{
				stickybit = 0;
				if (diff == 1){
					if((temp_m & 0x00000001) == 0) guardbit = 0;
					else guardbit = 0x00000002;
				}else guardbit = 0;
			}

			m2 = (m2 << 3) + 0x00000000;
			m1 = m1 >> diff;
			m1 = (m1 << 3) + (guardbit << 1) + stickybit;
			m = m2 - m1;

			overflow_m = m;

			if(((m>>3)>>24) == 0x00000001) m >>= 1, e = e + 1, overflow = 1;

			if(overflow == 1)
				guardbit = ((((overflow_m << 2) + guardbit) >> 1) & 0x00000003);

			unsigned int m_temp, e_temp, count=0;
			m_temp = m >> 3;
			e_temp = m_temp & 0x7f800000;
			e_temp >>= 23;

			while (e_temp == 0x00 || e_temp == 0xff){
				m = m << 1;
				m_temp = m_temp << 1;
				if (m == 0) return 0;
				count++;
				e_temp = m_temp & 0x7f800000;
				e_temp >>= 23;			
			}

			guardbit = ((m >> 1) & 0x00000003);
			stickybit = (m & 0x00000001);

			m >>= 3;

			if(guardbit == 0x00000003) m++;
			else if ((guardbit == 0x00000002) && stickybit == 1) m++;
			else if ((guardbit == 0x00000002) && stickybit == 0){
				if ((m & 0x00000001) == 0x00000001) m++;
			}
			else if((guardbit == 0x00000000) || (guardbit == 0x00000001)){
				// Truncate
			}

			m = m & 0x007fffff;
			
			if(count > 0){
				if(count >= e2){
					e = 0;
					//m = temp_m2 - (temp_m1 >> diff);
					m = (overflow_m << (e2-1)) >> 3;
				}
				else e = e2 - count;
			}

			if (e == 0x000000ff) {
				m = 0x00000000;
				result = ((s << 31) | (e << 23)) + m;
				return result;
			}

			result = ((s << 31) | (e << 23)) + m;

#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;
		}

		/* This if logic will add numbers of opposite signs if exponent of both numbers are same
			but have different mantissa */

		else if (m1 != m2){
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Both numbers have opposite sign, same exponent but different mantissa\n");
#endif
			if (m1>m2) m = m1 - m2, s = s1;
			else m = m2 - m1, s = s2;

			int m_temp;
			m_temp = m;

			unsigned int e_temp, count=0;
			e_temp = m & 0x7f800000;
			e_temp >>= 23;

			while (e_temp == 0x00 || e_temp == 0xff){
				m = m << 1;
				if (m == 0) return 0;
				count++;
				e_temp = m & 0x7f800000;
				e_temp >>= 23;				
			}

			if(isDeNormalized1 == 1 && isDeNormalized2 == 1)
				m = m_temp & 0x00ffffff;
			else
				m = m & 0x007fffff;

			if(isDeNormalized1 != 1 && isDeNormalized2 != 1){
				if(count >= e1){
					e = 0;
					m = m_temp << (e1-1);
				}
				else e = e1 - count;
			}

			result = ((s << 31) | (e << 23)) + m;
			
#if DO_DEBUGGING_PRINTS			
			fprintf(stderr, "final sign     :  0x%08x \n", s);
			fprintf(stderr, "final exponent :  0x%08x \n", e);
			fprintf(stderr, "final mantissaa:  0x%08x \n", m);
			fprintf(stderr, "final result   :  0x%08x \n", result);
#endif

			return result;

		}

		/* This else logic will add numbers of opposite signs if exponent of both numbers are same
		 	also both numbers have same mantissa.*/

		else{
#if DO_DEBUGGING_PRINTS	
			fprintf(stderr, "Both numbers have opposite sign, same exponent and same mantissa\n");
#endif

			return 0;
		}

	}

   return 0;
}
