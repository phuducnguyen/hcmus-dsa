#include <iostream>
#include <fstream>
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>

int main() {
    // Open the PDF file
    poppler::document pdf_document("path/to/your/pdf/file.pdf");

    if (!pdf_document.is_valid()) {
        std::cout << "Failed to open the PDF file." << std::endl;
        return 1;
    }

    // Create an output file stream
    std::ofstream output_file("path/to/your/output/file.txt");
    
    if (!output_file) {
        std::cout << "Failed to create the output file." << std::endl;
        return 1;
    }

    // Iterate through each page of the PDF document
    for (int page_index = 0; page_index < pdf_document.get_pages(); ++page_index) {
        const poppler::page pdf_page = pdf_document.create_page(page_index);

        // Extract the text from the current page
        std::string page_text = pdf_page.text().to_utf8();

        // Write the extracted text to the output file
        output_file << "Page " << (page_index + 1) << ":\n" << page_text << std::endl;
    }

    // Close the output file
    output_file.close();

    return 0;
}
