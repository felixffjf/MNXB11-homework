#include <TFile.h>
#include <TTree.h>
#include <TH2F.h>
#include "Momentum.h"

void read() {
    TFile *file = new TFile("tree_file.root", "READ"); // Open file
    TTree *tree = (TTree*)file->Get("tree"); // Get tree from file

    Momentum *obj = nullptr;
    tree->SetBranchAddress("momentumBranch", &obj); // Set branch address

    TH2F *hist = new TH2F("px_py", "px vs py", 100, -0.1, 0.1, 100, -0.1, 0.1);

    Int_t nEntries = tree->GetEntries();
    for (Int_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i); // Load entry into obj

        // Fill histogram with px and py
        hist->Fill(obj->GetPx(), obj->GetPy());
    }

    hist->Draw("COLZ"); // Draw histogram as a color map

    file->Close();
    delete hist;
    delete file;
}
