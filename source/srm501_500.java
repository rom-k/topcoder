public class FoxPlayingGame {
	public double theMax(int nA, int nB, int paramA, int paramB) {
		double scoreA  = (double)paramA / 1000.0;
		double scoreB  = (double)paramB / 1000.0;
		double score[]     = new double[nB+1];
		double score_min[] = new double[nB+1];
		
		for(int a=1; a<=nA; a++) {
			score[0] = score[0] + scoreA;
			score_min[0] = score[0];
			for(int b=1; b<=nB; b++) {
				double tmp1 = score[b]     + scoreA;
				double tmp2 = score_min[b] + scoreA;
				double tmp3 = score[b-1]     * scoreB;
				double tmp4 = score_min[b-1] * scoreB;
				
				score[b]     = tmp1;
				score_min[b] = tmp1;
				if (tmp2 > score[b]    ) {score[b]     = tmp2;}
				if (tmp2 < score_min[b]) {score_min[b] = tmp2;}
				if (tmp3 > score[b]    ) {score[b]     = tmp3;}
				if (tmp3 < score_min[b]) {score_min[b] = tmp3;}
				if (tmp4 > score[b]    ) {score[b]     = tmp4;}
				if (tmp4 < score_min[b]) {score_min[b] = tmp4;}
			}
		}
		
		return score[nB];
	}
}