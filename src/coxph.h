//------------------------------------------------------------------------------
//  GBM by Greg Ridgeway  Copyright (C) 2003
//
//  File:       coxph.h
//
//  License:    GNU GPL (version 2 or later)
//
//  Contents:   Cox proportional hazard object
//
//  Owner:      gregr@rand.org
//
//  History:    3/26/2001   gregr created
//              2/14/2003   gregr: adapted for R implementation
//
//------------------------------------------------------------------------------


#ifndef COXPH_H
#define COXPH_H

#include "distribution.h"
#include "matrix.h"

class CCoxPH : public CDistribution
{

public:

    CCoxPH();

    virtual ~CCoxPH();

    void ComputeWorkingResponse(double *adT,
				double *adDelta,
				double *adOffset,
				double *adF,
				double *adZ,
				double *adWeight,
				const bag& afInBag,
				unsigned long nTrain,
				int cIdxOff);

    void InitF(double *adT,
	       double *adDelta,
	       double *adOffset,
	       double *adWeight,
	       double &dInitF,
	       unsigned long cLength);
    
    void FitBestConstant(double *adT,
			 double *adDelta,
			 double *adOffset,
			 double *adW,
			 double *adF,
			 double *adZ,
			 const std::vector<unsigned long>& aiNodeAssign,
			 unsigned long nTrain,
			 VEC_P_NODETERMINAL vecpTermNodes,
			 unsigned long cTermNodes,
			 unsigned long cMinObsInNode,
			 const bag& afInBag,
			 double *adFadj,
			 int cIdxOff);
    
    double Deviance(double *adT,
                    double *adDelta,
                    double *adOffset,
                    double *adWeight,
                    double *adF,
                    unsigned long cLength,
		    int cIdxOff);

    double BagImprovement(double *adT,
                          double *adDelta,
                          double *adOffset,
                          double *adWeight,
                          double *adF,
                          double *adFadj,
                          const bag& afInBag,
                          double dStepSize,
                          unsigned long nTrain);


private:
    vector<double> vecdP;
    vector<double> vecdRiskTot;
    vector<double> vecdG;
    vector<unsigned long> veciK2Node;
    vector<unsigned long> veciNode2K;

    matrix<double> matH;
    matrix<double> matHinv;
};

#endif // COXPH_H



