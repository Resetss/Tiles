#pragma once

#include "../Core/Atlas.h"
#include "../Core/Selection.h"
#include "../Core/Base.h"

#include <string>

#include "imgui.h"

namespace Tiles
{

    class TextureSelectionPanel
    {
    public:
        TextureSelectionPanel() = default;
        ~TextureSelectionPanel() = default;

        void Render();
        // Setters
        void SetTextureAtlas(Shared<Atlas> atlas) { m_Atlas = atlas; }
        void SetSelection(Shared<Selection> selection) { m_Selection = selection; }
    private:
        // UI Rendering Methods
        void RenderAtlasPathSection();
        void RenderFileDialog();
        void RenderAtlasDimensionsSection();
        void RenderTextureGrid();

        // Helper Methods
        void HandleAtlasFileSelection(const std::string& newPath);
        void RenderTextureGridItem(int index, int x, int y);

        // File Dialog Methods
        void OpenFileDialog();
        void HandleFileDialogResult();

    private:
        // Texture Atlas State
        Shared<Atlas> m_Atlas;
        Shared<Selection> m_Selection;

        // Constants
        static constexpr float TEXTURE_BUTTON_SIZE = 40.0f;
        static constexpr float CHECKERBOARD_SIZE = 10.0f;
        static constexpr ImU32 SELECTION_BORDER_COLOR = IM_COL32(255, 165, 0, 255); // Orange
        static constexpr ImU32 DEAULT_BORDER_COLOR = IM_COL32(51, 51, 51, 255);     // Black
        static constexpr ImU32 CHECKERBOARD_COLOR_1 = IM_COL32(120, 120, 120, 255); // Dark gray
        static constexpr ImU32 CHECKERBOARD_COLOR_2 = IM_COL32(80, 80, 80, 255);    // Even darker gray
    };

}