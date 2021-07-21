#pragma once

namespace ph::system
{
    
	template <typename T>
    concept Darwin = true;
    
    template <typename T>
    concept Linux = false;
    
    template <typename T>
    concept Windows = false;
    
    template <typename T>
    concept X86_64 = false;
    
    template <typename T>
    concept Arm64 = true;
}
