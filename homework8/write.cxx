#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>
#include "Momentum.h"

void write() {
    TFile *file = new TFile("tree_file.root", "RECREATE"); // Open file for writing
    TTree *tree = new TTree("tree", "A tree with Momentum objects"); // Create TTree

    Momentum *obj = new Momentum(); // Initialize object
    tree->Branch("momentumBranch", "Momentum", &obj); // Create branch for object

    Int_t nEvents = 100; // Number of events

    for (Int_t i = 0; i < nEvents; i++) {
        // Generate random values for momentum components
        Float_t px = gRandom->Gaus(0, 0.02);
        Float_t py = gRandom->Gaus(0, 0.02);
        Float_t pz = gRandom->Gaus(0, 0.02);

        // Set momentum in the object
        obj->SetMomentum(px, py, pz);

        // Fill the tree with the current object
        tree->Fill();
    }

    tree->Write(); // Write tree to file
    file->Close(); // Close the file

    delete obj; // Clean up to avoid memory leak
    delete file;
}
